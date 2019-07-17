import threading
import time
def num(thread_name, start, end, delay):
	x=start
	while(x!=end):		
		time.sleep(delay)
		if(x%3==0 ):
			print (thread_name,x)
		x+=1
	
print_lock=threading.Lock()
t1=threading.Thread(target=num,args=("Thread1",1,30,0.01))
t2=threading.Thread(target=num,args=("Thread2",31,80,0.01))
t3=threading.Thread(target=num,args=("Thread3",81,100,0.01))

t1.start()
t1.join()
t2.start()
t2.join()
t3.start()
t3.join()
