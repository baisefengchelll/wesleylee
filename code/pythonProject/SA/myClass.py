# Python类的创建
'''
class ClassName:
    '' # 类文档信息
    class_suite # 类实体（成员，方法，数据属性）

'''
## 创建一个Employee类
class Employee:
    empCount = 0 # 类全局变量，被所有类的实例（对象）共享
    # 类对象
    def __init__(self, name, salary): # 类的初始化
        self.name_ = name
        self.salary_ = salary
        Employee.empCount += 1
    # 类方法
    def displayCount(self): # 打印Employee 数量
        print("Total Employee: %d" %Employee.empCount)
    
    def dispalyEmployee(self):
        print("Name: ", self.name_, ", Salary: ", self.salary_)    

class Test:
    def prt(gggg):
        print(gggg) # self代表类的实例，即地址
        print(gggg.__class__) # self.__class__指向方法
 