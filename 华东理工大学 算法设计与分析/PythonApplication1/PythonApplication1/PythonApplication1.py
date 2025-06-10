import difflib
import tkinter as tk
from tkinter import scrolledtext, messagebox
from tkhtmlview import HTMLLabel

# Color codes
RED = "#FF5733"
GREEN = "#00FF00"
ENDC = ""

def compare_code(code1, code2):
    differ = difflib.SequenceMatcher(None, code1, code2)
    diff_result = differ.get_opcodes()
    return diff_result

def show_comparison():
    code1 = text_box1.get("1.0", "end-1c")
    code2 = text_box2.get("1.0", "end-1c")
    
    diff_result = compare_code(code1, code2)
    comparison_text = ""
    for tag, i1, i2, j1, j2 in diff_result:
        if tag == 'equal':
            comparison_text += "Lines {} to {}: Code is equal\n".format(i1+1, i2)
            continue
        elif tag == 'replace':
            comparison_text += f"Lines {i1+1} to {i2}:\n"
            comparison_text += f"<font color='#FF5733'>Code in first input:</font><br>"
            comparison_text += code1[i1:i2] + "<br>"
            comparison_text += f"<font color='#00FF00'>Code in second input:</font><br>"
            comparison_text += code2[j1:j2] + "<br>"
        elif tag == 'delete':
            comparison_text += f"Lines {i1+1} to {i2}:\n"
            comparison_text += f"<font color='#FF5733'>Only in first input:</font><br>"
            comparison_text += code1[i1:i2] + "<br>"
        elif tag == 'insert':
            comparison_text += f"Lines {j1+1} to {j2}:\n"
            comparison_text += f"<font color='#00FF00'>Only in second input:</font><br>"
            comparison_text += code2[j1:j2] + "<br>"
    
    html_label.set_html(comparison_text)

def clear_text():
    text_box1.delete("1.0", "end")
    text_box2.delete("1.0", "end")
    html_label.set_html("")

# Create GUI
root = tk.Tk()
root.title("Code Comparison Tool")

# Input text boxes
label1 = tk.Label(root, text="Input 1:")
label1.grid(row=0, column=0, padx=5, pady=5, sticky="w")
text_box1 = scrolledtext.ScrolledText(root, width=40, height=10)
text_box1.grid(row=1, column=0, padx=5, pady=5)

label2 = tk.Label(root, text="Input 2:")
label2.grid(row=0, column=1, padx=5, pady=5, sticky="w")
text_box2 = scrolledtext.ScrolledText(root, width=40, height=10)
text_box2.grid(row=1, column=1, padx=5, pady=5)

# Comparison button
compare_button = tk.Button(root, text="Compare", command=show_comparison)
compare_button.grid(row=2, column=0, columnspan=2, pady=5)

# Output text box
html_label = HTMLLabel(root, html="")
html_label.grid(row=3, column=0, columnspan=2, padx=5, pady=5, sticky="nsew")

# Clear button
clear_button = tk.Button(root, text="Clear", command=clear_text)
clear_button.grid(row=4, column=0, columnspan=2, pady=5)

root.mainloop()
