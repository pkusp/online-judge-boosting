def reverse_matrix():
	pass


def main():
	mat = []
	for i in range(3):
		line = str(input()).strip().split()
		mat.append(line)
	res = reverse_matrix(mat)
	print(res)

if __name__ =='__main__':
	main()



