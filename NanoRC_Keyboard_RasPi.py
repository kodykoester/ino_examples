import serial
import sys

# Define Arduino serial port and baud rate
arduino_port = '/dev/ttyUSB0'  # Change this to your Arduino's port
baud_rate = 115200

# Create a serial object
ser = serial.Serial(arduino_port, baud_rate, timeout=1)

def send_command(command):
    ser.write(command.encode('utf-8'))

def main():
    print("Press arrow keys to control the RC car. Press 'q' to quit.")

    try:
        while True:
            key = input()

            if key == 'w':
                print("Forward")
                send_command("goStraight\n")
            elif key == 's':
                print("Backward")
                send_command("stopMotors\n")
            elif key == 'a':
                print("Left")
                send_command("turnLeft\n")
            elif key == 'd':
                print("Right")
                send_command("turnRight\n")
            elif key == 'q':
                print("Quitting.")
                send_command("stopMotors\n")
                break
            else:
                print("Stopping")
                send_command("stopMotors\n")

    except KeyboardInterrupt:
        print("\nExiting.")
    finally:
        ser.close()

if __name__ == "__main__":
    main()
