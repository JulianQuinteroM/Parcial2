class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def middle_node(head):
    middle = head
    end = head

    while end and end.next:
        middle = middle.next
        end = end.next.next

    return middle
