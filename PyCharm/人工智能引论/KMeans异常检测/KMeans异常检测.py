import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs

# 手动实现KMeans算法
class KMeans:
    def __init__(self, n_clusters=3, max_iter=300, tol=1e-4):
        self.n_clusters = n_clusters # 设置聚类数量(默认为3)
        self.max_iter = max_iter # 设置最大迭代次数(默认为300)
        self.tol = tol # 设置收敛阈值(默认为10^-4)
        self.centroids = None # 初始化聚类中心
        self.labels = None # 初始化样本标签

    # 定义用于训练KMeans模型的fit方法
    def fit(self, X):
        n_samples, n_features = X.shape # 保存输入数据X的样本数量和特征数量

        # 随机选择[n_clusters]个样本索引进行质心的初始化
        random_idx = np.random.choice(n_samples, self.n_clusters, replace=False) # 无放回地随机选择样本作为初始质心
        self.centroids = X[random_idx]

        # 进行迭代优化(最多[max_iter]次)
        for _ in range(self.max_iter):
            distances = self._calc_distances(X) # 计算每个样本到所有聚类忠心的距离
            self.labels = np.argmin(distances, axis=1) # 将样本分配到最近的聚类中心, 获得样本标签

            # 更新质心
            new_centroids = np.zeros_like(self.centroids) # 初始化新的聚类中心
            for i in range(self.n_clusters):
                cluster_samples = X[self.labels == i]
                if cluster_samples.size > 0:
                    new_centroids[i] = cluster_samples.mean(axis=0) # 对非空簇, 计算所有样本的均值作为新质心
                else:
                    new_centroids[i] = X[np.random.choice(n_samples)] # 对空簇, 随机选择一个样本作为新质心(对空簇进行处理防止后续迭代出错, 随机选择保持数据代表性同时提高效率)

            # 进行收敛判断
            if np.linalg.norm(new_centroids - self.centroids) < self.tol: # 检查新旧收敛中心的距离是否小于收敛值(使用numpy计算范围)
                break # 小于收敛值则停止迭代
            self.centroids = new_centroids # 更新聚类中心

    # 计算每个样本到所有质心的欧式距离
    def _calc_distances(self, X):
        distances = np.zeros((X.shape[0], self.n_clusters)) # 创建距离矩阵(全零数组), 存储每个样本到所有聚类中心的距离
        for i in range(self.n_clusters):
            distances[:, i] = np.linalg.norm(X - self.centroids[i], axis=1) # 计算每个样本到当前聚类中心的欧氏距离并存储到矩阵中
        return distances # 返回距离矩阵

    # 获取每个样本到所属簇质心的距离
    def get_distance_to_centroid(self, X):
        distances = self._calc_distances(X) # 计算距离矩阵
        return np.min(distances, axis=1) # 返回最小值

if __name__ == "__main__":
    np.random.seed(42) # 设置随机种子
    X_normal, _ = make_blobs(n_samples=300, centers=3, cluster_std=0.6, random_state=42) # 300个样本, 3个聚类, 标准差为0.6
    X_outliers = np.random.randn(5, 2) * 3 + np.array([10, 10]) # 生成5个异常点
    X = np.vstack([X_normal, X_outliers]) # 合并数据集(正常样本和异常点)

    # 数据标准化处理
    X = (X - np.mean(X, axis=0)) / np.std(X, axis=0)

    # 调用fit方法训练KMeans模型
    kmeans = KMeans(n_clusters=3)
    kmeans.fit(X)

    # 进行异常检测
    distances = kmeans.get_distance_to_centroid(X) # 获取距离
    threshold = np.mean(distances) + 2 * np.std(distances) # 计算异常值的阈值(距离均值+标准差2倍)
    outliers = np.where(distances > threshold)[0] # 距离 > 阈值的样本索引即为异常值

    # 可视化结果
    plt.figure(figsize=(10, 6))

    # 根据簇着色并绘制正常样本
    for i in range(kmeans.n_clusters):
        cluster_points = X[kmeans.labels == i]
        plt.scatter(cluster_points[:, 0], cluster_points[:, 1], label=f'Cluster {i + 1}')

    # 绘制异常值
    plt.scatter(X[outliers, 0], X[outliers, 1],
                c='red', marker='x', s=100, linewidths=2, label='Outliers')

    # 绘制聚类中心
    plt.scatter(kmeans.centroids[:, 0], kmeans.centroids[:, 1],
                c='black', marker='*', s=200, label='Centroids')

    plt.title("KMeans Clustering with Outlier Detection", fontsize=14) # 标题
    plt.xlabel("Feature 1 (Standardized)", fontsize=12) # X轴标签
    plt.ylabel("Feature 2 (Standardized)", fontsize=12) # Y轴标签
    plt.legend() # 显示图例
    plt.grid(True) # 显示网格
    plt.show()

    # 打印结果
    print("===== 结果如下 =====")
    print(f"聚类中心坐标:\n{kmeans.centroids}")
    print(f"异常值索引: {outliers}")
    print(f"异常值坐标:\n{X[outliers]}")