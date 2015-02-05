package main

import (
	"errors"
	"fmt"
)

func ask(how string) (string, error) {
	switch how {
	case "awesomely":
		return "Typeform", nil
	default:
		return "", errors.New("Can't ask without being awesome!")
	}

	// never reached
	return "", nil
}

func main() {
	how := "awesomely"
	fmt.Println(ask(how))
}
