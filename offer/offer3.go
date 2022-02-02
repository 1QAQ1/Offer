package main

func findRepeatNumber(nums []int) int {
	a := map[int]int{}
	for _, i := range nums {
		if _, sta := a[i]; sta {
			return i
		} else {
			a[i] = i
		}
	}
	return 0
}

func main() {
	nums := []int{1, 2, 3, 4, 2, 4}
	findRepeatNumber(nums)

}
