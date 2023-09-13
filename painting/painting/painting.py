import numpy as np
from PIL import Image
import tkinter as tk
from tkinter import filedialog


Filepath = ''
txtname = ''
root = tk.Tk()




frame1 = tk.Frame(root)
frame2 = tk.Frame(root)
root.title("���ֻ滭��")
label1 = tk.Label(frame1, text="��;��;��", justify=tk.LEFT)
label1.pack(side=tk.LEFT)
E1 = tk.Entry(frame1, bd =5)
E1.pack(side=tk.BOTTOM)
label2 = tk.Label(frame2, text="IMG_20200412_111015.jpg")
label2.pack()
tip = tk.Label(frame2, text="")
tip.pack()


def openw():
    global Filepath
    global txtname
    Filepath = filedialog.askopenfilename() #���ѡ��õ��ļ�
    print(Filepath)
    txtname = Filepath.replace(Filepath.split("/")[-1].split(".")[-1],"txt")
    print(txtname)
    label2["text"] = Filepath.split("/")[-1]

def ST():
    global Filepath
    global txtname
    str = E1.get().split(";")
    if len(str)<2:
        tip["text"] = "����ȷ���������滭���ַ�"
        return
    print("------------",Filepath)

    im = Image.open(Filepath)
    im = im.resize((300, 300), Image.ANTIALIAS)
    image = im.convert('L')
    image = np.array(image)
    if len(str) == 3:
        with open(txtname, 'w') as f:
            for i in range(len(image)):
                for j in range(len(image[0])):
                    st = int(image[i][j] / 85)
                    if st == 0:
                        f.write(str[0])
                    else:
                        if st == 1:
                            f.write(str[1])
                        else:
                            f.write(str[2])
                    f.write(" ")
                f.write("\n")
    if len(str) == 2:
        with open(txtname, 'w') as f:
            for i in range(int(len(image))):
                for j in range(int(len(image[0]))):
                    if image[i][j] > 95:
                        f.write(str[0])
                    else:
                        f.write(str[1])
                    # f.write(str(abs(int((255 - binary[int(i)][int(j)])/255)-1)))
                f.write("\n")

select = tk.Button(frame2, text="ѡ���ļ�", command=openw)
select.pack()
start = tk.Button(frame2, text="��ʼת��", command=ST)
start.pack()

frame1.pack(padx=1, pady=1)
frame2.pack(padx=10, pady=10)

root.mainloop()
