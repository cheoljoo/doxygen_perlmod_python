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
                width=500,
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
#content = extract_braces_content(sample_text)
#print("Extracted Content:")
#print(content)

class Solution:
    def __init__(self,inpuml,outjson,debug):
        self.inpuml = inpuml
        self.outjson = outjson
        self.debug = debug
        self.uml = []
        self.json = {}
         #a = [1,2,3,4]
         #pprint({ 'a' : a })
        lines = []
        with open(self.inpuml, 'r') as file:
            lines = file.readlines()

        self.startFlowChart = re.compile('^```puml\s*:\s*func-FlowChart\s*:\s*(?P<func>.*)\s*$')
        self.startSequenceDiagram = re.compile('^```puml\s*:\s*func-SequenceDiagram\s*:\s*(?P<func>.*)\s*$')
        self.startUmlRe = re.compile('^\s*@startuml\s*$')
        self.endUmlRe = re.compile('^\s*@enduml\s*$')

        for line in lines:
            if not line.strip():
                continue
            grp = self.startFlowChart.search(line)
            if grp:
                self.func = grp.group('func')
                self.func_no_space = self.func.replace(' ','')
                self.kind = 'flowchart'
                 #print(grp.group('func'))
                continue
            grp = self.startSequenceDiagram.search(line)
            if grp:
                self.func = grp.group('func')
                self.func_no_space = self.func.replace(' ','')
                self.kind = 'sequencediagram'
                 #print(grp.group('func'))
                continue
            if self.endUmlRe.search(line):
                self.uml.append(line)
                if self.func_no_space not in self.json:
                    self.json[self.func_no_space] = { 'func': self.func, 'flowchart':[] , 'sequencediagram':[] }
                self.json[self.func_no_space][self.kind] = self.uml
                self.uml = []
                continue
            self.uml.append(line.replace('::','__'))

         #pprint({'json':self.json})
        with open(self.outjson, 'w') as file:
            print('write:',self.outjson , '<- self.json')
            json.dump({ 'json':self.json } ,file,indent = 4)


if (__name__ == "__main__"):

    parser = argparse.ArgumentParser(
        prog=sys.argv[0],
        description=
        'parse plantuml from doxygen_flowchart'
    )
    parser.add_argument( '--debug', default=False , action="store_true" , help="debug mode on  default : false")
    parser.add_argument( '--inpuml', type=str,default='plantuml.md' , 
            help='input plantuml file  default:plantuml.md')
    parser.add_argument( '--outjson', type=str,default='parse-out.json' , 
            help='output json from --inpuml       default:parse-out.json')
    args = parser.parse_args()

    S = Solution(args.inpuml,args.outjson,args.debug)


