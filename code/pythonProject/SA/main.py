from SA import MySA

instance1 = MySA(T0=100, alpha=0.99, Tf=0.01, loopNum=100)
instance1.optSolution_, instance1.optObjValue_ = instance1.Run()
print('Optimum Solution: ', instance1.optSolution_)
print('Optimum Value: ', instance1.optObjValue_)
# instance1.iniSol_ = instance1.GerIniSol() # 生成一个初始解
# instance1.objValue_ = instance1.ObjFun(sol = instance1.iniSol_) # 计算目标值
# print('Initial Solution: ',instance1.iniSol_,
#       'Initial Objective Value: ', instance1.objValue_)