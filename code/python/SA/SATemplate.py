# 定义SA类
class SA:
    '''
    SA类，模拟退火算法
    '''
    
    def __init__(self, T0, alpha, Tf, loopNum): # data
        self.T0_ = T0 # 初始温度
        self.alpha_ = alpha # 降温系数
        self.curT_ = T0 # 当前温度
        self.Tf_ = Tf # 终止温度
        self.loopNum_ = loopNum # 内循环次数
        self.iniSol_ = None # 初始解
        self.curSol_ = None # 当前解
        self.newSol_ = None # 新解
        self.objValue_ = None # 目标值
        self.optSolution_ = None # 最优解
        self.optValue_ = None # 最优值
        
    def ObjFun(self):
        '目标函数'
        pass
    
    def GerIniSol(self):
        '生成初始解'
        pass 
    
    def GerNewSol(self):
        '生成新解'
        pass
    
    def RenewSol(self):
        '更新解'
        pass
    
    
    def Run(self): # run the simulated annealing
        self.iniSol_ = self.GerIniSol() # 生成初始解
        while(self.curT_ > self.Tf_):
            for i in range(self.loopNum_):
               self.RenewSol() #更新解
            self.curT_ = self.curT_ * self.alpha_ # 降温
        self.optSolution_ = self.curSol_  # 获取最优解
        self.optObjValue_ = self.ObjFun(sol = self.optSolution_)  #计算最优值
        return self.optSolution_, self.optObjValue_
    
    
