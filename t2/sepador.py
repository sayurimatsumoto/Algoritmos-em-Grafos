farqui = open("t2.in",'r')
i = 0
k = 0
while(k < 14):
	name = "testes/"+str(i)+".in"
	#s = farqui.readline()
	w, h = [int(x) for x in next(farqui).split()]
	farqui2 = open(name, "w")
	farqui2.write(str(w)+ " "+str(h)+"\n")
	print (h)
	for x in range(0, h):
		num = farqui.readline()
		farqui2.write(num)
	farqui2.write("0 0")	
	i += 1
	k += 1	