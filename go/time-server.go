package main

import (
	"fmt"
	"net"
	"os"
	"time"
)

func main() {
	// 地址为零，表示所有的接口。如果不指定端口的，会自动分配一个。
	service := ":1200"
	tcpAddr, err := net.ResolveTCPAddr("tcp4", service)
	checkError(err)

	// ListenTCP 的第一个返回值为 TCPListener 类型指针
	listener, err := net.ListenTCP("tcp", tcpAddr)
	checkError(err)

	for {
		conn, err := listener.Accept()
		if err != nil {
			fmt.Println("Listen error:", err.Error())
			continue
		}
		daytime := time.Now().String()
		conn.Write([]byte(daytime))
		conn.Close()
	}
}

func checkError(err error) {
	if err != nil {
		fmt.Println("Error :", err.Error())
		os.Exit(1)
	}
}
