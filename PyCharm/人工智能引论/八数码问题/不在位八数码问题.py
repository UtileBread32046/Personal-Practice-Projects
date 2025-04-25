def misplaced_tiles(state, goal):
    """
    计算不在位数字的数量（启发函数h(n)）
    :param state: 当前状态（二维列表）
    :param goal: 目标状态（二维列表）
    :return: 不在正确位置的非零数字数量
    """
    count = 0
    for i in range(3):  # 遍历3行
        for j in range(3):  # 遍历3列
            # 如果当前格子非空且与目标状态不同，计数器加1
            if state[i][j] != 0 and state[i][j] != goal[i][j]:
                count += 1
    return count

def find_zero(state):
    """
    找到空格(0)的位置
    :param state: 当前状态
    :return: (row, col) 零的位置
    """
    for i in range(3):  # 遍历3行
        for j in range(3):  # 遍历3列
            if state[i][j] == 0:  # 找到值为0的格子
                return (i, j)
    return None  # 如果没有找到0（理论上不应该发生）

def deepcopy_2d_list(lst):
    """手动实现二维列表的深拷贝"""
    return [row[:] for row in lst]  # 对每一行进行切片复制

# 曼哈顿距离函数
def manhadun(state, goal):
    distance = 0
    goal_pos = {goal[i][j]: (i, j) for i in range(3) for j in range(3)}
    for i in range(3):
        for j in range(3):
            num = state[i][j]
            if num != 0:
                goal_i, goal_j = goal_pos[num]
                distance += abs(i - goal_i) + abs(j - goal_j)
    return distance

# 宽度优先搜索
def bfs(initial_state, goal_state):
    def zero_heuristic(state, goal):
        return 0
    return a_star(initial_state, goal_state, zero_heuristic)

def a_star(initial_state, goal_state, heuristics): # 增加"启发"函数
    # 设置计数器
    expand = 0 # 扩展节点计数
    generate = 0 # 生成节点计数
    """
    A*算法求解8数码问题（不使用import的实现）
    :param initial_state: 初始状态
    :param goal_state: 目标状态
    :return: 移动路径或None(无解)
    """
    # 定义可能的移动方向（上、下、左、右）及其对应的名称
    moves = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    move_names = ['上', '下', '左', '右']

    # 使用列表模拟优先队列，手动维护排序
    open_list = []
    # 初始状态：f(n)=h(n), g(n)=0, 路径为空
    # initial_h = misplaced_tiles(initial_state, goal_state)
    initial_h = heuristics(initial_state, goal_state) # 替换原有运算
    open_list.append((initial_h, 0, initial_state, []))

    # 使用集合存储已访问状态，避免重复处理
    close_list = set()
    close_list.add(tuple(map(tuple, initial_state)))  # 将列表转换为元组以便哈希

    while open_list:  # 当开放列表不为空时循环
        expand += 1
        # 手动实现优先队列：每次取出前先按f(n)排序
        open_list.sort(key=lambda x: x[0])  # 根据f值排序
        f, g, state, path = open_list.pop(0)  # 取出f值最小的节点

        if state == goal_state:  # 如果当前状态是目标状态
            return path, expand, generate  # 返回路径和计数器

        zero_row, zero_col = find_zero(state)  # 找到空格位置

        # 尝试四个方向的移动
        for idx, (dr, dc) in enumerate(moves):
            generate += 1
            new_row, new_col = zero_row + dr, zero_col + dc  # 计算新位置

            # 检查新位置是否在合法范围内
            if 0 <= new_row < 3 and 0 <= new_col < 3:
                # 手动实现深拷贝创建新状态
                new_state = deepcopy_2d_list(state)
                # 交换空格和目标位置
                new_state[zero_row][zero_col], new_state[new_row][new_col] = new_state[new_row][new_col], new_state[zero_row][zero_col]

                state_tuple = tuple(map(tuple, new_state))  # 转换为可哈希的元组

                if state_tuple not in close_list:  # 如果新状态未被访问过
                    new_g = g + 1  # 更新g值（路径成本）
                    # new_h = misplaced_tiles(new_state, goal_state)  # 计算h值
                    new_h = heuristics(new_state, goal_state) # 替换原有运算
                    # 将新状态加入开放列表
                    open_list.append((new_g + new_h, new_g, new_state, path + [move_names[idx]]))
                    close_list.add(state_tuple)  # 将新状态标记为已访问

    return None  # 如果开放列表为空仍未找到解，返回无解



# 8数码测试用例
initial = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8]  # 0表示空格
]

# # 15数码测试用例
# initial = [
#     []
# ]

goal = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 0]
]

# # 运行A*算法
# solution = a_star(initial, goal)
# 测试A*（不在位数）
solution_h1, expand_h1, generate_h1 = a_star(initial, goal, misplaced_tiles)
# 测试A*（曼哈顿距离）
solution_h2, expand_h2, generate_h2 = a_star(initial, goal, manhadun)
# 测试BFS
solution_bfs, expand_bfs, generate_bfs = bfs(initial, goal)

# 输出结果
if solution_h1:
    print("找到h1解决方案！移动步骤如下：")
    for i, move in enumerate(solution_h1, 1):  # 从1开始计数
        print(f"步骤{i}: 空格向{move}移动")
    print("expand计数: ", expand_h1)
    print("generate计数: ", generate_h1)
else:
    print("无解！")
print("")

if solution_h2:
    print("找到h2解决方案！移动步骤如下：")
    for i, move in enumerate(solution_h2, 1):  # 从1开始计数
        print(f"步骤{i}: 空格向{move}移动")
    print("expand计数: ", expand_h2)
    print("generate计数: ", generate_h2)
else:
    print("无解！")
print("")

if solution_h1:
    print("找到bfs解决方案！移动步骤如下：")
    for i, move in enumerate(solution_bfs, 1):  # 从1开始计数
        print(f"步骤{i}: 空格向{move}移动")
    print("expand计数: ", expand_bfs)
    print("generate计数: ",  generate_bfs)
else:
    print("无解！")