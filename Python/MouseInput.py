#Made this to unlike songs on Spotify WebPlayer
import pyautogui
import time
import keyboard

Width = pyautogui.size().width #Get width
Height = pyautogui.size().height #Get height
Speed = 0.1 #Speed of cursor to move to the specified location. !EDIT AS YOU PREFER!
TotalClicks = 0
CurrentY = 665 #Default Y position. !EDIT AS YOU PREFER!
DecrementY = 55 #Decrement by 55 to CurrentY position if needed. !EDIT AS YOU PREFER!

CurrentX = 890 #Default X Position. !EDIT AS YOU PREFER!

print("---------------Spotify WebPlayer Unlike Songs---------------")
print(f"[+] Screen Width And Height Are: {Width}x{Height}")
print("[!] Spam the Q key to stop the script")

try:
	while True:
		time.sleep(0.1) #Giving time to position on last liked song on the page. !EDIT AS YOU PREFER!
		pyautogui.moveTo(CurrentX, CurrentY, Speed) #Moves mouse cursor to current coordinates at given speed
		print(f"[+] Current Width And Height: {CurrentX}x{CurrentY}")
		pyautogui.click() #Click
		TotalClicks = TotalClicks + 1
		print(f"[+] Song Removed")
		CurrentY = CurrentY - DecrementY
		pyautogui.moveTo(CurrentX, CurrentY, Speed) #Moves mouse cursor to updated coordinates
		if keyboard.is_pressed('q'):
			print("[!] Q was pressed. Exiting...")
			print(f"[+] Total Clicks : {TotalClicks}")
			break
		if CurrentY <= 275: #If Y position goes below/or is equal to 275, reset Y position
			print(f"[!] Y Position Was {CurrentY} . Resetting to default value")
			CurrentY = 665
except KeyboardInterrupt:
	pass
