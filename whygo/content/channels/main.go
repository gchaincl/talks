package main

import "log"
import "math/rand"
import "time"

const WORKERS = 10

func work(c chan<- bool) {
	defer func() {
		c <- true
	}()
	time.Sleep(time.Duration(rand.Intn(3000)) * time.Millisecond)
}

func main() {
	workers := make(chan bool, WORKERS)

	for i := 0; i < WORKERS; i++ {
		go work(workers)
	}
	for i := 0; i < WORKERS; i++ {
		<-workers
		log.Printf("%d missing\n", (WORKERS-i)-1)
	}
}
