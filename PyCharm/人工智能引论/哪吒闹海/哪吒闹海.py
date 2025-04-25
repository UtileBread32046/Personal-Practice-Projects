import pygame
import sys
import time

# 初始化Pygame
pygame.init()

# 设置窗口大小
screen_width = 800
screen_height = 600
screen = pygame.display.set_mode((screen_width, screen_height))
clock = pygame.time.Clock()  # 新增时钟对象
pygame.display.set_caption("哪吒之魔童闹海")

# 加载哪吒的图片
ne_zha_image = pygame.image.load("ne_zha.png")
ne_zha_image = pygame.transform.scale(ne_zha_image, (78, 124))
ne_zha_rect = ne_zha_image.get_rect()
ne_zha_rect.center = (screen_width // 3.5, screen_height - 160)

# 加载地面图片
ground_image = pygame.image.load("ground.png")
ground_image = pygame.transform.scale(ground_image, (screen_width, 100))
ground_rect = ground_image.get_rect()
ground_rect.topleft = (0, screen_height - 100)

# 定义角色的速度和重力a
move_speed = 2
jump_speed = -5  # 调整跳跃速度
fall_speed = 0.09  # 调整下落速度
is_jumping = False
jump_count = 0  # 跳跃计数器
max_jump_time = 1200  # 跳跃持续时间（假设每秒60帧，1秒=60帧）
velocity_y = 0  # 垂直速度

# 初始化字体
font = pygame.font.SysFont("Arial", 24)

# 创建提示文字
instruction_text = font.render("Tips --- A&D: Move; J: Attack; K: Jump", True, (0, 0, 0))

# 火球类
class Fireball(pygame.sprite.Sprite):
    def __init__(self, x, y):
        super().__init__()
        self.image = pygame.image.load("fireball.png")  # 火球图片
        self.image = pygame.transform.scale(self.image, (75, 75))  # 调整火球图片大小
        self.rect = self.image.get_rect()
        self.rect.center = (x, y)
        self.speed = 2  # 火球的速度

    def update(self):
        self.rect.x += self.speed  # 火球向右移动
        if self.rect.x > screen_width:  # 如果火球飞出屏幕，消失
            self.kill()

# 敌人类
class Enemy(pygame.sprite.Sprite):
    def __init__(self, x, y):
        super().__init__()
        self.image = pygame.image.load("enemy.png")  # 敌人图片
        self.image = pygame.transform.scale(self.image, (50, 50))  # 调整敌人图片大小
        self.rect = self.image.get_rect()
        self.rect.center = (x, y)
        self.speed = 0.5005  # 敌人向左的速度

    def update(self):
        self.rect.x -= self.speed  # 敌人向左移动
        if self.rect.right < 0:  # 如果敌人移出屏幕，消失
            self.kill()

# 创建火球组
fireball_group = pygame.sprite.Group()

# 创建敌人组
enemy_group = pygame.sprite.Group()

# 初始化计分系统
score = 0
score_text = font.render(f"Score: {score}", True, (0, 0, 0))

# 初始化生命值
health = 5
health_text = font.render(f"Health: {health}", True, (0, 0, 0))

# 敌人生成时间控制
last_enemy_time = time.time()

# 状态标志：记录J和K键是否已被按下
j_pressed = False
k_pressed = False

# 游戏主循环
running = True
game_over = False
while running:
    dt = clock.tick(240)/1000  # 获取帧时间（秒）
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    if not game_over:
        # 获取键盘按键状态
        keys = pygame.key.get_pressed()

        # 移动控制
        if keys[pygame.K_a]:  # A键
            ne_zha_rect.x -= move_speed
        if keys[pygame.K_d]:  # D键
            ne_zha_rect.x += move_speed

        # 限制角色在屏幕左右边界内移动
        if ne_zha_rect.left < 0:
            ne_zha_rect.left = 0
        if ne_zha_rect.right > screen_width:
            ne_zha_rect.right = screen_width

        # 跳跃控制
        if not is_jumping:
            if keys[pygame.K_k] and not k_pressed:  # K键
                is_jumping = True
                jump_count = 0
                velocity_y = jump_speed
                k_pressed = True  # 锁定K键
        else:
            # 更新垂直速度
            velocity_y += fall_speed
            ne_zha_rect.y += velocity_y
            jump_count += 1

            # 限制跳跃持续时间
            if jump_count >= max_jump_time:
                is_jumping = False
                jump_count = 0
                velocity_y = 0

            # 检测与地面的碰撞
            if ne_zha_rect.colliderect(ground_rect):
                ne_zha_rect.y = ground_rect.top - ne_zha_rect.height
                is_jumping = False
                jump_count = 0
                velocity_y = 0

        # 发射火球
        if keys[pygame.K_j] and not j_pressed:  # 按下J键
            fireball = Fireball(ne_zha_rect.centerx + 40, ne_zha_rect.centery)  # 创建火球，位置在哪吒的右边
            fireball_group.add(fireball)
            j_pressed = True  # 锁定J键

        # 更新所有火球
        fireball_group.update()

        # 检测火球和敌人的碰撞
        for fireball in fireball_group:
            for enemy in enemy_group:
                if pygame.sprite.collide_rect(fireball, enemy):
                    fireball.kill()  # 火球消失
                    enemy.kill()  # 敌人消失
                    score += 5  # 增加积分

        # 生成新敌人，每2秒刷新一个
        if time.time() - last_enemy_time > 2:  # 2秒钟生成一个新的敌人
            new_enemy = Enemy(screen_width, screen_height - 150)  # 新敌人位置
            enemy_group.add(new_enemy)
            last_enemy_time = time.time()  # 更新生成敌人的时间

        # 更新敌人位置
        enemy_group.update()

        # 检测角色与敌人的碰撞
        for enemy in enemy_group:
            # 修改这里，使用 ne_zha_rect.colliderect 方法
            if ne_zha_rect.colliderect(enemy.rect):
                enemy.kill()  # 敌人消失
                health -= 1  # 减少生命值
                if health <= 0:
                    game_over = True

    # 填充背景颜色
    screen.fill((255, 255, 255))

    # 绘制操作提示文字
    screen.blit(instruction_text, (10, 10))  # 在屏幕正上方绘制提示文字

    # 绘制分数
    score_text = font.render(f"Score: {score}", True, (0, 0, 0))
    screen.blit(score_text, (screen_width - 150, 10))  # 绘制分数在右上角

    # 绘制生命值
    health_text = font.render(f"Health: {health}", True, (0, 0, 0))
    screen.blit(health_text, (screen_width - 150, 40))  # 绘制生命值在右上角

    # 绘制地面
    screen.blit(ground_image, ground_rect)

    if not game_over:
        # 绘制哪吒的形象
        screen.blit(ne_zha_image, ne_zha_rect)
    else:
        # 游戏结束提示
        game_over_text = font.render("Game Over", True, (255, 0, 0))
        screen.blit(game_over_text, (screen_width // 2 - 50, screen_height // 2 - 20))

    # 绘制火球
    fireball_group.draw(screen)

    # 绘制敌人
    enemy_group.draw(screen)

    # 更新显示
    pygame.display.flip()

    # 释放按键
    if not keys[pygame.K_j]:
        j_pressed = False
    if not keys[pygame.K_k]:
        k_pressed = False

# 退出游戏
pygame.quit()
sys.exit()
