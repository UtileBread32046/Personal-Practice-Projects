# 水果蔬菜识别系统
def judge_repeat(value, check_list):
    return value in check_list

def print_rule(condition, result):
    print(f"应用规则：{condition} → {result}")

# 初始化特征字典
features = {
    '1': '甜味',    '2': '酸味',    '3': '苦味',    '4': '辣味',
    '5': '直接食用', '6': '用于烹饪', '7': '多汁',    '8': '红色',
    '9': '圆形',    '10': '黄色',   '11': '软皮',    '12': '紫色',
    '13': '绿色',   '14': '长条',   '15': '圆锥形',  '16': '球状',
    '17': '分层',   '18': '脆',     '19': '硬',      '20': '弯曲',
    '21': '水果',   '22': '蔬菜',   '23': '香蕉',    '24': '苹果',
    '25': '葡萄',   '26': '黄瓜',   '27': '胡萝卜',   '28': '洋葱'
}

# 产生式规则库 (格式：[[条件列表], 结论])
rules = [
    [['5'], '21'],        # 直接食用→水果
    [['6'], '22'],        # 用于烹饪→蔬菜
    [['1', '8', '9'], '24'],  # 甜+红+圆→苹果
    [['10', '20', '11'], '23'],  # 黄+弯+软→香蕉
    [['7', '2', '12'], '25'],  # 多汁+酸+紫→葡萄
    [['13', '14', '18'], '26'],  # 绿+长+脆→黄瓜
    [['10', '15', '19'], '27'],  # 橙+圆锥+硬→胡萝卜
    [['12', '16', '17'], '28'],  # 紫+球+分层→洋葱
    [['1'], '21'],        # 甜味→可能水果
    [['2'], '21'],        # 酸味→可能水果
    [['3'], '22'],        # 苦味→可能蔬菜
    [['4'], '22'],        # 辣味→可能蔬菜
    [['7'], '21'],        # 多汁→可能水果
    [['18'], '22']        # 脆→可能蔬菜
]

print('''请输入特征编号：
==============================
1:甜味  2:酸味  3:苦味  4:辣味  
5:直接食用  6:用于烹饪  7:多汁
8:红色   9:圆形   10:黄色 11:软皮
12:紫色  13:绿色  14:长条 15:圆锥形
16:球状 17:分层  18:脆   19:硬
20:弯曲
==============================
输入0开始推理''')

# 综合数据库
fact_list = []
while True:
    num = input("输入特征编号：")
    if num == '0':
        break
    if num in features and not judge_repeat(num, fact_list):
        fact_list.append(num)
        print(f"添加事实：{features[num]}")
    else:
        print("无效或重复特征")

print("\n初始事实：", [features[f] for f in fact_list])

# 推理引擎
changed = True
while changed:
    changed = False
    for rule in rules:
        conditions, conclusion = rule
        # 检查所有条件是否满足
        if all(c in fact_list for c in conditions):
            # 检查结论是否尚未存在
            if not judge_repeat(conclusion, fact_list):
                fact_list.append(conclusion)
                print_rule(
                    ' ∧ '.join([features[c] for c in conditions]),
                    features[conclusion]
                )
                changed = True
                break  # 每次只应用一条规则

# 最终结论判断
print("\n推理过程完成，最终事实：", [features[f] for f in fact_list])

result = "无法识别"
for f in fact_list:
    if f in ['23','24','25','26','27','28']:
        result = features[f]
        break

if result == "无法识别":
    if '21' in fact_list:
        result = "未知水果"
    elif '22' in fact_list:
        result = "未知蔬菜"

print(f"\n识别结果：{result}")
