class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """

        x={1:"I",5:"V",10:"X",50:"L",100:"C",500:"D",1000:"M"}
        if num in x:
            return x[num] 
        elif num<10:
            ans=digit1(num)
        elif num<100:
            ans=digit2(num) 
        elif num<1000:
            ans=digit3(num)   
        else:
            ans=digits4(num)    
        ans=final(ans)
        ans3=[]
        for i in ans:
            ans3.append(str(i))

        ans2=''.join(ans3)
        return ans2
              

def digit1(d):
    x={1:"I",5:"V"}
    ans=[]
    if d==0:
        return []
    elif d in x:
        return x[d]
    elif d<4:
        for _ in range(d):
            ans.append("I")
    elif d==4:
        return ["I","V"]
    
    elif d<9:
        ans.append("V")
        for i in range(d-5):
            ans.append("I")
    else:
        return ["I","X"]  
    return ans
def digit2(d):
    x={10:"X",50:"L",100:"C"}
    ans=[]
    if d==0:
        return []
    elif d in x:
        return x[d]
    elif d<40:
        for i in range(d//10):
            ans.append("X")
    elif d==40:
        return ["X","L"]
    elif d<50:
        ans=["X","L"]
    elif d<90:
        ans.append("L")
        for _ in range((d-50)//10):
            ans.append("X")
    elif d==90:
        return ["X","C"]
    else:
        ans=["X","C"]
    z=[digit1(d-(d//10*10))]
    if z==[0]:
        return ans
    else:
        return ans+z 
def digit3(d):
    x={100:"C",500:"D"}
    ans=[]
    if d==0:
        return []
    elif d in x:
        return x[d]
    elif d<400:
        for i in range(d//100):
            ans.append("C")
    elif d==400:
        return ["C","D"]
    elif d<500:
        ans=["C","D"]
    elif d<900:
        ans=["D"]
        for i in range((d-500)//100):
            ans.append("C")
    else:
        ans=["C","M"]        
    z=[digit2(d-(d//100*100))]
    if z==[0]:
        return ans
    else:
        return ans+z
def digits4(d):
    ans=[]
    for _ in range(d//1000):
        ans.append("M")   
    z=[digit3(d-(d//1000*1000))]
    if z==[0]:
        return ans
    else:
        return ans+z  
def final(x):
    ans=[]
    for i in x:
        if type(i)==list:
            ans.extend(final(i))
        else:
            ans.append(i)
    return ans


        