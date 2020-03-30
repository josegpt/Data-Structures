package linkedlist

import (
	"reflect"
	"strconv"
	"testing"
)

func TestAddFirst(t *testing.T) {
	tt := []int{2, 4, 5, 10, 1000}

	for i, val := range tt {
		t.Run(strconv.Itoa(i), func(t *testing.T) {
			ll := New()
			ll.AddFirst(val)
			got, _ := ll.GetFirst()
			equals(t, got.data, val)
		})
	}

	for i, val := range tt {
		t.Run(strconv.Itoa(i), func(t *testing.T) {
			ll := New()
			ll.AddFirst(i)
			ll.AddFirst(val)
			got, _ := ll.Get(val)
			equals(t, got.data, val)

			want := 2
			l := ll.Len()

			equals(t, l, want)
		})
	}
}

func TestAddLast(t *testing.T) {
	tt := []int{2, 4, 5, 10, 1000}

	for i, val := range tt {
		t.Run(strconv.Itoa(i), func(t *testing.T) {
			ll := New()
			ll.AddLast(i)
			ll.AddLast(i)
			ll.AddLast(val)
			got, _ := ll.GetLast()
			equals(t, got.data, val)

			want := 3
			l := ll.Len()

			equals(t, l, want)
		})
	}
}

func TestToArray(t *testing.T) {
	t.Run("slice with ints", func(t *testing.T) {
		want := []int{2, 4, 5, 10, 1000}

		ll := New()
		for _, val := range want {
			ll.AddLast(val)
		}
		got := ll.ToArray()

		if !reflect.DeepEqual(got, want) {
			t.Errorf("got %v but wanted %v", got, want)
		}
	})

	t.Run("empty slice", func(t *testing.T) {
		want := []int{}

		ll := New()
		got := ll.ToArray()

		if !reflect.DeepEqual(got, want) {
			t.Errorf("got %v but wanted %v", got, want)
		}
	})
}

func TestInsertBefore(t *testing.T) {
	tt := []int{2, 4, 5, 10, 1000}

	for i, val := range tt {
		t.Run(strconv.Itoa(i), func(t *testing.T) {
			ll := New()
			ll.InsertBefore(0, 12)
			ll.InsertBefore(12, i)
			ll.InsertBefore(12, val)
			got, err := ll.Get(val)
			if err != nil {
				t.Fatal(err)
			}

			equals(t, got.data, val)
		})
	}
}

func TestInsertAfter(t *testing.T) {
	tt := []int{2, 4, 5, 10, 1000}

	for i, val := range tt {
		t.Run(strconv.Itoa(i), func(t *testing.T) {
			ll := New()
			ll.InsertAfter(0, 12)
			ll.InsertAfter(12, i)
			ll.InsertAfter(12, val)
			got, err := ll.Get(val)
			if err != nil {
				t.Fatal(err)
			}

			equals(t, got.data, val)
		})
	}

	t.Run("key not found", func(t *testing.T) {
		ll := New()
		ll.InsertAfter(0, 12)
		_, err := ll.Get(25)

		if err.Error() != KeyNotFound {
			t.Errorf("got %v but wanted %v", err.Error(), KeyNotFound)
		}
	})
}

func TestRemove(t *testing.T) {
	tt := []int{2, 4, 5, 10, 1000}

	for i, val := range tt {
		t.Run(strconv.Itoa(i), func(t *testing.T) {
			ll := New()
			ll.AddFirst(val)
			got, _ := ll.Remove(val)

			equals(t, got.data, val)
		})
	}

	for i, val := range tt {
		t.Run(strconv.Itoa(i), func(t *testing.T) {
			ll := New()
			ll.AddFirst(val)
			ll.AddFirst(i)
			got, _ := ll.Remove(val)

			equals(t, got.data, val)
		})
	}
}

func TestContains(t *testing.T) {
	tt := []int{2, 4, 5, 10, 1000}

	for i, val := range tt {
		t.Run(strconv.Itoa(i), func(t *testing.T) {
			ll := New()
			ll.InsertAfter(0, 12)
			ll.InsertAfter(12, i)
			ll.InsertAfter(12, val)
			got := ll.Contains(val)
			want := true

			if got != want {
				t.Errorf("got %v but wanted %v", got, want)
			}
		})
	}

	for i, val := range tt {
		t.Run(strconv.Itoa(i), func(t *testing.T) {
			ll := New()
			ll.InsertAfter(0, 12)
			got := ll.Contains(val)
			want := false

			if got != want {
				t.Errorf("got %v but wanted %v", got, want)
			}
		})
	}
}

func TestClear(t *testing.T) {
	tt := []int{2, 4, 5, 10, 1000}

	for i, val := range tt {
		t.Run(strconv.Itoa(i), func(t *testing.T) {
			ll := New()
			ll.AddFirst(val)

			ll.Clear()

			got := ll.Len()
			want := 0

			if got != want {
				t.Errorf("got %v but wanted %v", got, want)
			}
		})
	}

	t.Run("empty list", func(t *testing.T) {
		ll := New()

		ll.Clear()

		got := ll.Len()
		want := 0

		if got != want {
			t.Errorf("got %v but wanted %v", got, want)
		}
	})
}

func equals(t *testing.T, got, want int) {
	t.Helper()
	if got != want {
		t.Errorf("got %v but wanted %v", got, want)
	}
}
