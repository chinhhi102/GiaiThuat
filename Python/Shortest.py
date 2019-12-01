from collections import defaultdict


class PriorityQueue(object):
	# Hàm sẽ chạy khi vào được khởi tạo
    def __init__(self):
        self.queue = []
#    def __str__(self):
#        return ' '.join([str(i) for i in self.queue])

    # for checking if the queue is empty
    def isEmpty(self):
        return len(self.queue) == []

    # for inserting an element in the queue
    def insert(self, data):
        self.queue.append(data)

    # for popping an element based on Priority
    def delete(self):
        try:
            max = 0
			#Chạy vòng lặp lấy biến max
            for i in range(len(self.queue)):
                if self.queue[i] > self.queue[max]:
                    max = i
			#Gán max vào trong item
            item = self.queue[max]
			#Xóa max
            del self.queue[max]
			#Trả max về cho hàm gọi
            return item
		#Kiểm tra lỗi
        except IndexError:
            print()
            return ("none","none")

class Graph:
	#Khởi tạo giá trị ban đầu với tham số truyền vào là dữ liệu đọc được ở file airline-data
    def __init__(self, tZ):
		#Khởi tạo 1 đồ thị với kiểu dữ liệu là defaultdict(list) cái này t xem tham khảo của thầy thôi
        self.graph = defaultdict(list)
		#Khởi tạo số đỉnh của đồ thị là 23 trong bài
        self.V = len(tZ)
        #self.visited = [False] * self.V
		#Khởi tạo thời gian với cặp {địa điểm:múi giờ} cái này giống như sử dụng địa điểm như vị trí của mảng
		#Thay vì giả sử m gọi giá trị của mảng như là A[1] = 2 gì gì đó thì giờ m có thể sử dụng địa điểm như là vị trí
		#Nên m có thể sử dụng A["Hello"] = 1 chức năng cũng tương tự cái trên
        self.timeZone = tZ
		
		#Thêm cạnh vào Đồ thị với tham số truyền vào là tên đường bay và mã đường bay tiếp đến là
		#src : Địa điểm bay, dest : Địa điểm đến, weight : thời gian bay 
    def addEdge(self, airline, MA, src, dest, weight):
		#Tạo 1 nút vào vector cạnh, nếu rảnh t sẽ giải thích thêm nhưng đại khái là
		#1 sân bay đại diện cho 1 đỉnh và đỉnh đó nối với nhiều đỉnh khác tạo thành cạnh
		#Giống như đỉnh 1 nối với đỉnh 2 và 3 tạo ra cạnh 1-2, 1-3 và cạnh đó có trọng số nữa thì
		#Ta nói cạnh 1-2 có trọng số là a cạnh 1-3 có trọng số là b bla bla
		#Còn ở đây t thêm src chính là đỉnh 1 còn dest là đỉnh nó nối tạo ra trọng số weight với mã là airline,MA
        newNode = [weight, airline, MA, dest]
		#Thêm nút đó vào đồ thị
        self.graph[src].insert(0,newNode)
        #print("Success")
		
		#Hàm tìm đường đi ngắn nhất với 2 tham số truyền vào là điểm bắt đầu và điểm đến
    def Dijkstra(self, S, T):
        #define vo cung = 1.000.000
        oo = 1000000
		#Đầu tiên khởi tạo khoảng cách là kiểu directory, lên mạng để hiểu thêm thông tin về kiểu này
		#Hay ở trên có nói trong phần timeZone
        distance = {}
		#mảng vis cũng tương tự để kiểm tra xem đỉnh đó đã xét hay chưa
        vis = {}
		#1 mảng chỉ đường đi để sau khi duyệt xoq ta đệ quy để lấy đường đi
        path = {}
		#Tạo biến q với kiểu dữ liệu PriorityQueue, gọi thế này nó sẽ chạy đến hàm init trong class
        q = PriorityQueue()
		#Khởi tạo tất cả các địa điểm vs khoảng cách oo, cái này trong thuật toán có nói, khởi tạo cả các đỉnh là chưa xét với mảng vis
        for i in self.timeZone:
            distance[i] = oo
            vis[i] = False
        #Vị trí đầu tiên bằng 0
		distance[S] = 0
		#Sau đó thêm vị trí đầu tiên với khoảng cách 0 vào trong hàng đợi
        q.insert((0,S))
		#Chạy đến khi nào hàng đợi rỗng
        while not q.isEmpty():
			#Đầu tiên ta phải xác định được ta cần lấy gì
			#Trong hàng đợi có 2 dữ liệu là khoảng cách tối ưu hiện tại của nó với điểm xuất phát và tên của đỉnh đó
			#Vậy thì với khoảng cách ta thêm vào chỉ để lấy khoảng cách nhỏ nhất( Theo thuật toán Dijkstra) là vị trí 0
			#thì ta chỉ cần lấy cái đỉnh ta đang xét là vị trí 1
			#Chỗ này nó chạy đến hàm delete của thằng class PriorityQueue
            u = q.delete()[1]
			#Nếu như nó trả về "none" tức ngoài vùng thì thoát vòng lặp while vì nó ko còn gì để xét
            if u == "none":
                break
			#Còn nếu như đỉnh đó đã xét rồi thì sẽ bỏ qua
            if(vis[u]):
                continue
			#Nếu không đánh dấu đỉnh đó là xét rồi
            vis[u] = True
			#Sau đó chạy biến v là tất cả các cạnh của đỉnh đó
			#Biến v này sẽ bao gồm:
				#index 0(tức v[0]): là weight
				#index 1: là airline
				#index 2: là MA
				#index 3: là dest
				#4 biến này là 4 chỉ số ở newNode ta thêm ở trên (xem phần AddEdge)
            for v in self.graph[u]:
				#Nếu như khoảng cách từ đỉnh đang xét(cạnh u) + với trọng số từ cạnh đang xét với cạnh v
				#Mà lớn hơn khoảng cách tối ưu trước có của cạnh v thì 
                if distance[u] + v[0] < distance[v[3]]:
					#Đầu tiên là tối ưu khoảng cách của cạnh v
                    distance[v[3]] = distance[u] + v[0]
					#Tiếp theo là lưu lại đường đi tới cạnh v với 4 chỉ số là điểm nó tối ưu là u, v1, v2 là mã chuyến bay, v0 là trọng số
                    path[v[3]] = (u, v[1], v[2], v[0])
					#Sau đó thêm vào hàng đợi khoảng -trọng số của đĩnh đã tối ưu và đỉnh đó
					#Vì thằng hàng đợi tìm max mà mình cần tìm min nên đối dấu => max->min và min->max vd như số 100>50 sau khi đổi dấu -100<50
                    q.insert((-distance[v[3]],v[3]))
		#Sau khi đã tìm xoq thì nếu như điểm đến là oo tức là không có được đi => xuất ko có đường đi
        if distance[T] == oo:
            print("Not Found the Route")
        else:
		#Ngược lại xuất ra thời gian bay
            print("Amount of time of the route is : ",distance[T])
			#Sau đó dùng đệ quy để tìm đường
			#Cái đệ quy này đơn giản
			#Giả sử ta có đường từ a->b và đường thế này
			#a->c->d->b thì do ta đã lưu a = 0, c = a, rồi d = c rồi b = d trước đó nên khi ta có điểm đến là b 
			# ta cứ đệ quy ngược lại b = d -> d = c -> c = a -> a = 0 thì ngừng
            print("Path: ")
            print("Name_Air_Port\tAir_Line\t\tFlight\t\t\tTime_of_Fight")
            bb = False
            while T in path.keys():
                #if bb:
                #    print("   *   \n  ***  \n   *   \n   *   ")
                for i in path[T]:
                    print(i,end=" |\t\t\t")
                print()
                T = path[T][0]
                bb = True

#Read Airport-data in file
def readAirport():
	#Mở file lên
    airport = open('D:/Assignment 1/airport-data.txt',"r")
	#Ép kiểu int vào n => n là dòng đầu tiên
    n = int(airport.readline());
	#Sau đó khai báo kiểu dữ liệu directory như đã nói ở trên
    timeZone = {}
	#Sau đó chạy vòng n vòng lặp
    for _ in range(0,n):
		#Cho dữ liệu vào tạo thành mảng data và mỗi data sẽ bị cắt theo từng 1 tab
		#ví dụ ngta cho địa điểm cách thời gian 1 tab => data sẽ là mảng 2 phần từng
		#với data0 là địa điểm và data1 là thời gian
        data = airport.readline().split('\t')
        timeZone[data[0]] = int(data[1])//100
	#Trả về dữ liệu thu được
    return timeZone

#Read Flight-data in file
def readFlight():
	#Mở file
    flight = open('D:/Assignment 1/flight-data.txt', "r")
	#Dòng này do không biết lặp bao nhiêu lần nên sẽ sử dụng iter(lambda:)
	#Nó sẽ chạy đến khi nào gặp kí tự '' tức là không còn gì để đọc sẽ ngừng
    for i in iter(lambda: flight.readline(),''):
		#Và dòng dữ liệu đọc được là biến i
		#i này sẽ được đưa vào data như 1 mảng đã nói trên
        data = i.split('\t')
		#Nếu như dữ liệu không đủ 8 biến như trong tiêu chuẩn đề bài thì bỏ qua
		#8 biến lần lượt là:
		#index 0 hay data[0]:Tên đường bay
		#index 1:Mã của chuyến bay
		#index 2:Điểm cấp cánh
		#index 3:Thời gian với 2 số cuối là phút 1 or 2 số đầu là giờ
		#index 4:kiểu giờ PM hay AM
		#index 5:Điểm hạ cánh
		#index 6:Thời gian với 2 số cuối là phút 1 or 2 số đầu là giờ
		#index 7:kiểu giờ PM hay AM
        if len(data)<7:
            continue
		#Tính thời gian lúc hạ cánh = giờ(giờ chia lấy nguyên 100 để lấy 1 hay 2 số đầu rồi chia dư của 12 để 12h -> 0h rùi *60
		#Vì cần quy đổi đơn vị chung là phút) + với phút (chia lấy dư 100 để lấy 2 số cuối) + với 12 tiếng nếu là PM và trừ đi timeZone
        tmE = int(data[6])//100%12*60 + int(data[6])%100 + 12*60*(data[7][0] == 'P') - graph.timeZone[data[5]]*60
		#Tính thời gian cấp cánh cũng y trang
        tmS = int(data[3])//100%12*60 + int(data[3])%100 + 12*60*(data[4][0] == 'P') - graph.timeZone[data[2]]*60
        #Nếu như thời gian tới < thời gian lúc bắt đầu đi chứng tỏ nó đã bay qua đêm tức là qua ngày mới vậy phải +24h
		if (tmE <= tmS):
           tmE += 24*60
		#Trọng số = thời gian tới - thời gian bắt đầu bay
        w = tmE - tmS
		#Thêm cạnh mới(Gọi hàm trong class)
        graph.addEdge(data[0], data[1], data[2], data[5], w)

#Main
#Tạo 1 biến timeZone để lưu dữ liệu của Airline-data sau đó gọi hàm ra
timeZone = readAirport()
#Tạo 1 đồ thị với tham số truyền vào là 1 timeZone để nó vào hàm init khởi tạo
graph = Graph(timeZone)
#Đọc dữ liệu Flight-data
readFlight()
#Nhập điểm đầu và điểm đến cần tính
x,y = input().split()
#Sau đó gọi hàm tính khoảng cách là xoq
graph.Dijkstra(x,y)