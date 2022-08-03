def reverse_string(arg):
    newstr=""
    if isinstance(arg, list) and list:
        sz = len(arg)
        queue = []
        for i in range(sz-1,-1,-1):
            queue.append(arg[i])
            while (queue):
                if isinstance(queue[-1],list):
                    for j in range(0,len(queue[-1])):
                        queue.insert(len(queue)-1,queue[-1][j])
                else:
                    element = str(queue[-1])
                    for i in range(len(element)-1,-1,-1):
                        newstr+=element[i]
                queue.pop(-1)
    else:
        arg = str(arg)
        for i in range(len(arg)-1,-1,-1):
            newstr+=arg[i]
            
    return newstr
    
    
arg=[[1,2,3,4],[2,3,4],[3,[3,4,5,6]],4, ["43211"]]
arg2="1234"
arg3=1234
print(reverse_string(arg))
print(reverse_string(arg2))
print(reverse_string(arg3))
