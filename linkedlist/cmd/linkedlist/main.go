package main

import (
	"fmt"

	"github.com/josegpt/Data-Structures/linkedlist"
)

func main() {
	fmt.Println("*** LinkedList ***")
	ll := linkedlist.New()

	ll.AddFirst(0)
	ll.AddFirst(1)
	ll.AddLast(4)
	ll.Remove(1)
	ll.InsertAfter(0, 5)
	ll.InsertBefore(4, 3)
	fmt.Println("Contains:", ll.Contains(5))
	n, _ := ll.Get(0)
	fmt.Println("Get:", n)
	n, _ = ll.GetFirst()
	fmt.Println("Get First:", n)
	n, _ = ll.GetLast()
	fmt.Println("Get Last:", n)
	fmt.Println(ll.ToArray())
	fmt.Println(ll)
	ll.Clear()
	ll.AddLast(1)
	fmt.Println(ll)
}
