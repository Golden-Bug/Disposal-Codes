import threading
import time
def num(thread_name, start, end, delay):
	for i in range(start,end):		
		time.sleep(delay)
		if(i<=10 ):
			print (thread_name,"HI")
		if(i>10 and i<=30 ):
			print (thread_name,"HELLO")
		if(i>30 ):
			print (thread_name,"BYE")


		
	
print_lock=threading.Lock()
t1=threading.Thread(target=num,args=("Thread1",1,10,0.1))
t2=threading.Thread(target=num,args=("Thread2",11,30,0.1))
t3=threading.Thread(target=num,args=("Thread3",31,80,0.1))

t1.start()
t1.join()
t2.start()
t2.join()
t3.start()
t3.join()
print("Main Thread Exit")


