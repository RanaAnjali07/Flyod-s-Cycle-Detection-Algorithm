
class Node:
	def __init__(self, d):
		self.data = d
		self.next = None

head = None


def detectLoop(head):
	slowPointer = head
	fastPointer = head

	while (slowPointer != None
		and fastPointer != None
		and fastPointer.next != None):
		slowPointer = slowPointer.next
		fastPointer = fastPointer.next.next
		if (slowPointer == fastPointer):
			return 1

	return 0


head = Node(21)
head.next = Node(22)
head.next.next = Node(23)
head.next.next.next = Node(24)
head.next.next.next.next = Node(25)


temp = head
while (temp.next != None):
	temp = temp.next

temp.next = head


if (detectLoop(head)):
	print("Loop exist in the linked list")
else:
	print("Loop does not exist in the linked list")

