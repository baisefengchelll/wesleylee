from SATemplate import SA
import random as rd
import math

class MySA(SA):
    def __init__(self, T0, alpha, Tf, loopNum):
        # 调用父类构造函数
        super().__init__(T0, alpha, Tf, loopNum)
        self.iniSol_:float = None
        self.curSol_:float = None
        self.newSol_:float = None
        self.objValue_:float = None
        self.optSolution_:float = None
        self.optValue_:float = None
    def ObjFun(self, sol):
        '目标函数'
        self.objValue_ = sol**2 + 2*sol +1
        return self.objValue_
    
    def GerIniSol(self):
        '随机生成初始解'
        self.iniSol_ = rd.randint(-3, 3)
        self.curSol_ = self.iniSol_
        print('Initial Solution: ', self.iniSol_)
        return self.iniSol_
    
    def GerNewSol(self):
        '生成新解'
        print('Current Solution: ', self.curSol_)
        self.newSol_ = self.curSol_ + rd.uniform(-1, 1)
        print('New Solution: ', self.newSol_)
        return self.newSol_
    
    def RenewSol(self):
        '更新解'
        self.newSol_ = self.GerNewSol() ## 基于当前解产生一个新解
        objValue_new = self.ObjFun(sol = self.newSol_)
        objValue_cur = self.ObjFun(sol = self.curSol_)
        delta = objValue_new - objValue_cur
        if(delta<=0): ## delta<=0意味新解有改进,返回新解
            self.curSol_ = self.newSol_
        else:
            'Metropolis法则'
            p = rd.random() #随机生成一个概率
            P = math.exp(-delta/self.curT_)
            if(P>p):
                self.curSol_ = self.newSol_
            else:
                self.curSol_ = self.curSol_
        print('Renew Solution: ', self.curSol_)
    