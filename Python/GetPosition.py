import pyautogui
import time
import keyboard

Width = pyautogui.size().width #Get width
Height = pyautogui.size().height #Get height

print(f"[+] Screen Width And Height Are: {Width}x{Height}")
print("[!] Spam the Q key to stop the script")

try:
	while True:
		time.sleep(1)
		CurrentPosition = pyautogui.position()
		CurrentX = CurrentPosition[0] #Getting X position
		CurrentY = CurrentPosition[1] #Getting Y position
		print(f"[+] Current Mouse Position: X = {CurrentX}, Y = {CurrentY}")
		if keyboard.is_pressed('q'):
			print("[+] Q was pressed. Exiting...")
			break
		time.sleep(1)
except KeyboardInterrupt:
	pass
