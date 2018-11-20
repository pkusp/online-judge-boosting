# i got it


def rand_query(s):
	lst=s.split(" ")
	length=len(lst)
	res=""
	res=lst[RAND()%length]
	while length>0:
		res=res+lst[RAND()%length]
		del lst[RAND()%length]
		length-=1
	return res



	RAND()%len(lst)


