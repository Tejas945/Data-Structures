name = "Pythonmasternumberone"
d = {}
for c in name:
    if c not in d:
        d[c]=1
    else:
        d[c] +=1
  
  print(d)      
# =====Output========
#{'P': 1, 'y': 1, 't': 2, 'h': 1, 'o': 2, 'n': 3, 'm': 2, 'a': 1, 's': 1, 'e': 3, 'r': 2, 'u': 1, 'b': 1}
#====================

#======Using default dict=========
from collections import defaultdict
d = defaultdict
for c in name:
    d[c] +=1
    
 d
