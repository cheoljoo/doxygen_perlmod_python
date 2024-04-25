#from collections import defaultdict
#import numpy as np

import sys
import os
import argparse
import math
import random
# https://www.daleseo.com/python-typing/
from typing import Optional
from typing import Union
from typing import List
from typing import Final
from typing import Dict
from typing import Tuple
from typing import Set
import re
import csv
import json
import mysetting
import datetime

from pprint import PrettyPrinter
import re

custom_printer = PrettyPrinter(
                indent=2,
                width=100,
                depth=6,
                compact=True,
                sort_dicts=False
                #underscore_numbers=True
                )
pprint = custom_printer.pprint




def extract_braces_content(text):
    # DOTALL 플래그를 사용하여 개행 문자도 포함하여 매치합니다.
    pattern = r'\{([^{}]*?)\}'
    match = re.search(pattern, text, re.DOTALL)
    if match:
        return match.group(1)  # 중괄호 안의 내용만 반환합니다.
    else:
        return None

# 테스트를 위한 멀티라인 문자열
sample_text = """
function example() {
    var config = {
        option1: true,
        option2: "value",
        option3: [1, 2, 3]
    };
    return config;
}
"""

# 함수 호출 및 결과 출력
content = extract_braces_content(sample_text)
print("Extracted Content:")
print(content)

class Solution:
    def __init__(self,inpuml,outjson,debug):
        self.inpuml = inpuml
        self.outjson = outjson
        self.debug = debug
         #a = [1,2,3,4]
         #pprint({ 'a' : a })
        lines = []
        with open(self.inpuml, 'r') as file:
            lines = file.readlines()

        self.startClassRe = re.compile('^\s*(?P<stype>.*)\s*(?P<type>\S+)\s+(?P<name>\S+)\s+{\s*$')
        self.dashRe = re.compile('.--')
        self.classes = {}
        current_class = None
        self.relationship = { 'inheritance':[] , 'nested':[] , 'aggregation':[] }
        self.relationshipPriority = { 'inheritance':0 , 'nested':1 , 'aggregation':2 }
        self.relationshipFinal = {}
        current_relationship = None

        types = ['class','enum']
        for line in lines:
            if not line.strip():
                continue
            line = line.rstrip()
            grpStartClass = self.startClassRe.search(line)
            if grpStartClass:
                if self.debug: print('line:',grpStartClass.group('stype'),':',grpStartClass.group('type'),':',grpStartClass.group('name'),':',line)
                typeFind = ''
                for type in types:
                    if line.find(type) >= 0:
                        typeFind = type
                        break
                else:
                    print('! warning: this line does not have {t} type in '.format(t=types),line)

                # 클래스 이름 추출
                parts = line.split()  # 'class ClassName {' 형태를 가정
                if self.debug: pprint({'line.split':parts})
                if len(parts) > 1:
                    class_name = parts[-2] if parts[-1] == '{' else parts[-1].rstrip('{')
                    stype = parts[:-3]
                    self.classes[class_name] = {'prior-type':stype, 'type':typeFind,'name':class_name, 'fields': [], 'methods': [] , 'all':[] }
                    current_class = class_name
                    self.classes[current_class]['all'].append(line)
            elif line == '}':
                # 클래스 정의 끝
                self.classes[current_class]['all'].append(line)
                current_class = None
            elif current_class:
                # 멤버 변수 또는 메서드 추출
                if '(' in line:
                    # 메서드로 가정
                    method_info = line.split('(')[0].strip()
                    self.classes[current_class]['methods'].append(method_info)
                else:
                    # 멤버 변수로 가정
                    field_info = line.strip()
                    self.classes[current_class]['fields'].append(field_info)
                self.classes[current_class]['all'].append(line)
            else:
                 #print(line)
                if line.strip() == """/' Inheritance relationships '/""":
                    current_relationship = 'inheritance'
                    continue
                elif line.strip() == """/' Aggregation relationships '/""":
                    current_relationship = 'aggregation'
                    continue
                elif line.strip() == """/' Nested objects '/""":
                    current_relationship = 'nested'
                    continue
                if current_relationship and line.strip().find('--') >= 0:
                    self.relationship[current_relationship].append(line)
                    a = line.split()
                    if len(a) != 3:
                        print('it is not relationship type:',line)
                        continue
                    if a[1].find('--') >= 0:
                        start =  a[0][1:] if a[0].startswith('.') else a[0]
                        end = a[2][1:] if a[2].startswith('.') else a[2]
                        current_priority = self.relationshipPriority[current_relationship]
                        if start+'---'+end not in self.relationshipFinal:
                            self.relationshipFinal[start+'---'+end] = { 'priority':current_priority, 'relationship':current_relationship, 'from':start , 'link':a[1] , 'to':end }
                        elif self.relationshipFinal[start+'---'+end]['priority'] > current_priority:
                            self.relationshipFinal[start+'---'+end] = { 'priority':current_priority, 'relationship':current_relationship, 'from':start , 'link':a[1] , 'to':end }
                    else:
                        print('it is not relationship type:',line)
                        continue
                elif current_relationship:
                    print(line)


         #pprint({'classes':self.classes})
        with open(self.outjson, 'w') as file:
            print('write:',self.outjson , '<- self.classes self.relationship self.relationshipFinal')
            json.dump({ 'classes':self.classes , 'relationship':self.relationship , 'relationshipFinal':self.relationshipFinal } ,file,indent = 4)


if (__name__ == "__main__"):

    parser = argparse.ArgumentParser(
        prog=sys.argv[0],
        description=
        'parse hpp2plantuml result'
    )
    parser.add_argument( '--debug', default=False , action="store_true" , help="debug mode on  default : false")
    parser.add_argument( '--inpuml', type=str,default='all.puml' , 
            help='input plantuml file  default:all.puml')
    parser.add_argument( '--outjson', type=str,default='parse-out.json' , 
            help='output json from --inpuml       default:parse-out.json')
    args = parser.parse_args()

    S = Solution(args.inpuml,args.outjson,args.debug)


