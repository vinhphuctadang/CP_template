# import sys # to have access to sys.stdin
# from collections import deque # for using deque
# # deque append, appendleft, pop, popleft
# from queue import PriorityQueue
# from bisect import bisect_left as lower_bound, bisect_right as upper_bound # C/C++ alike function
# # array generation, e.g: __array(10, 5) stands for: int a[10][5], support multi-dimensional array (list-likelihood)
def __array (*arg):

	if len (arg) == 0:
		raise ValueError ('Array of no dimension')

	prod = 1
	for i in arg:
		prod *= i
	__main = [0] * prod

	def __recurse (__main, *arg):
		if len (arg) == 1:
			return __main
		__nxt = []
		idx = 0
		step = arg[0]
		__len = len (__main)
		while idx < __len:
			__nxt.append (__main [idx:idx+step])
			idx += step
		return __recurse (__nxt, *arg[1:])
	return __recurse (__main, *arg[::-1])


oo = 2000000000

def main ():
	# # your code goes here
	pass

### service generate
# def handle (nhu):

if __name__=='__main__':
	main ()
'''
Sorry for leaving the caution here
Template for Competitive Programming with Python 3.x
Template is under no license, so do not hesitate to use, 
but I have no intention to take responsibilty of any problems occured
Uncomment above lines to import (do not encourage to import all, had better be needs)
PEACE
Contact me via gmail:
vinhphuctadang@gmail.com
'''
