import copy

N = int(input())

template = ["  *  ",
            " * * ",
            "*****"]

factor = 0
while 3*(2**factor) < N:
    new_template = copy.deepcopy(template)

    for i in range(len(template)):
        new_template[i] = template[i] + " " + template[i]
        

    for i in range(len(template)):
        template[i] = " "*(3*(2**factor)) + template[i] + " "*(3*(2**factor))
        
    for i in range(len(template)):
        template.append(new_template[i])
    
    factor += 1


print('\n'.join(template))