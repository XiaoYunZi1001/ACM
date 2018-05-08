import logRegres
from numpy import *
dataArr,labelMat = logRegres.loadDataSet()

# 未优化的算法结果
#weights = logRegres.gradAscent(dataArr,labelMat)
#logRegres.plotBestFit(weights.getA())

# 随机梯度上升算法
# weights = logRegres.stoGradAscent0(array(dataArr),labelMat)
# logRegres.plotBestFit(weights)

# 改进的随机梯度上升算法
weights = logRegres.stocGradAscent1(array(dataArr),labelMat)
logRegres.plotBestFit(weights)