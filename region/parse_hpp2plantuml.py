import re

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

