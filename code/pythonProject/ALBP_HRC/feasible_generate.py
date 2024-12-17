def Initial(NT:int, NS:int, NH:int, NR:int, 
            th_i:list, tr_i:list, p_i:list, rpw_i:list, t_i:list):
    stc:int = 0 # station数量初始化为0
    while(stc<=NS): # station外循环
        stc = stc + 1
        stop:set # 分配给当前站台的operator集合
        opct = 0 # 当前站台的opertaor的完成时间初始化为0
        clt:set # 分配的当前站台的候选任务集合
        while(clt!=None): # 集合非空，进入循环
            st_clt_opct = opct # clt的开始时间
            co_clt_opct # clt的完成时间
            slt = select(clt) # 从clt中随机选择的一个任务，选择策略——轮盘赌
            if(jt_slt==None): # 空集以为非HRC任务
                st_slt_opct
                co_slt_opct
            else:
                jt_slt
                st_slt_opct == st_jt_slt_opct
                co_slt_opct == co_jt_slt_opct
        update_clt()
        update_opct()
        update_feasible_solution()
        return feasible_solution