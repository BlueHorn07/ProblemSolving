class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
      parlen = 2 * n
      
      
      def backtrack(len: int) -> List[str]:
        if len == 0: return [("", 0, 0)]
        
        prevret = backtrack(len - 1)
        
        retlist = []
        
        for ret in prevret:
          par = ret[0]
          opencnt = ret[1] # should opencnt <= n
          closecnt = ret[2] # should opencnt >= closecnt and closecnt <= n
          
          # add open
          if opencnt + 1 <= n: 
            retlist.append((par + "(", opencnt + 1, closecnt))
          
          # add close
          if closecnt + 1 <= n and opencnt >= closecnt + 1: 
            retlist.append((par + ")", opencnt, closecnt + 1))
            
        return retlist
      
      ret = backtrack(parlen)
      
      finalret = []
      for par in ret:
        finalret.append(par[0])
      
      return finalret
      
