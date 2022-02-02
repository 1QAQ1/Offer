package offer6

type ListNode struct {
	Val  int
	Next *ListNode
}

func reversePrint(head *ListNode) []int {
	stack := make([]int, 0)
	starksize := 0
	fakehead := head
	for fakehead != nil {
		stack = append(stack, fakehead.Val)
		fakehead = fakehead.Next
		starksize++
	}
	ret := make([]int, starksize)
	for i := 0; i < starksize; i++ {
		ret[i] = stack[starksize-1-i]
	}
	return ret
}
