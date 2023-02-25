class Solution:
    def tribonacci(self, n: int) -> int:
        if not hasattr(self, 'mylist'):
            self.mylist=[0,1,1]
        
        if n > len(self.mylist)-1:
            for i in range(len(self.mylist)-3, n):
                self.mylist.append(self.mylist[i]+self.mylist[i+1]+self.mylist[i+2])
        
        return self.mylist[n]
