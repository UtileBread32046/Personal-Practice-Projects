import numpy as np
import skfuzzy as fuzz
from skfuzzy import control as ctrl
import matplotlib.pyplot as plt

# 定义论域
x_stain = np.arange(0, 101, 1)    # 污泥论域 0-100
x_oil = np.arange(0, 101, 1)      # 油脂论域 0-100
x_time = np.arange(0, 121, 1)     # 时间论域 0-120

# 创建模糊控制变量
stain = ctrl.Antecedent(x_stain, 'stain')    # 输入1：污泥量
oil = ctrl.Antecedent(x_oil, 'oil')          # 输入2：油脂量
wash_time = ctrl.Consequent(x_time, 'time')  # 输出：洗涤时间

# 定义隶属函数（自动三角隶属函数）
stain.automf(3, names=['SD', 'MD', 'LD'])  # 3个等级：少、中、多
oil.automf(3, names=['NG', 'MG', 'LG'])    # 3个等级：少、中、多

# 自定义洗涤时间的隶属函数
wash_time['VS'] = fuzz.trimf(x_time, [0, 0, 30])    # 很短
wash_time['S'] = fuzz.trimf(x_time, [0, 30, 60])    # 短
wash_time['M'] = fuzz.trimf(x_time, [30, 60, 90])   # 中等
wash_time['L'] = fuzz.trimf(x_time, [60, 90, 120])  # 长
wash_time['VL'] = fuzz.trimf(x_time, [90, 120, 120])# 很长

# 可视化隶属函数
stain.view()
oil.view()
wash_time.view()
plt.show()

# 定义模糊规则
rules = [
    ctrl.Rule(stain['SD'] & oil['NG'], wash_time['VS']),  # 规则1
    ctrl.Rule(stain['SD'] & oil['MG'], wash_time['M']),   # 规则2
    ctrl.Rule(stain['SD'] & oil['LG'], wash_time['L']),   # 规则3
    ctrl.Rule(stain['MD'] & oil['NG'], wash_time['S']),   # 规则4
    ctrl.Rule(stain['MD'] & oil['MG'], wash_time['M']),   # 规则5
    ctrl.Rule(stain['MD'] & oil['LG'], wash_time['L']),   # 规则6
    ctrl.Rule(stain['LD'] & oil['NG'], wash_time['M']),   # 规则7
    ctrl.Rule(stain['LD'] & oil['MG'], wash_time['L']),   # 规则8
    ctrl.Rule(stain['LD'] & oil['LG'], wash_time['VL'])   # 规则9
]

# 创建控制系统
washing_ctrl = ctrl.ControlSystem(rules)
washing_sim = ctrl.ControlSystemSimulation(washing_ctrl)

# 设置输入值
washing_sim.input['stain'] = 60  # 污泥量
washing_sim.input['oil'] = 70    # 油脂量
 
# 执行模糊推理
washing_sim.compute()

# 输出结果
print(f"推荐洗涤时间：{washing_sim.output['time']:.2f} 分钟")

# 可视化推理过程
wash_time.view(sim=washing_sim)
plt.show()
