# Updated data to reflect only the requested data types (c, s, d, i, u, x, X, p)
data_filtered = {
    "Flag": [\"0", "-", \"+", \" ", \"#"],
    "Character (c)": [
        "Ignored for characters.", 
        "Left-align within the given field width.", 
        "Ignored for characters.",
        "Ignored for characters.",
        "Ignored for characters."
    ],
    "String (s)": [
        "Pads with spaces or zeros (on the left).", 
        "Left-align within the given field width.", 
        "Ignored for strings.",
        "Ignored for strings.",
        "Ignored for strings."
    ],
    "Integer (d/i)": [
        "Pads with zeros (on the left). Ignored if '-'.", 
        "Left-align within the given field width.", 
        "Always show sign (+/-).",
        "Add a space before positive numbers.",
        "Ignored for integers."
    ],
    "Unsigned (u)": [
        "Pads with zeros (on the left). Ignored if '-'.", 
        "Left-align within the given field width.", 
        "Ignored for unsigned.",
        "Ignored for unsigned.",
        "Ignored for unsigned."
    ],
    "Hex (x/X)": [
        "Pads with zeros (on the left). Ignored if '-'.", 
        "Left-align within the given field width.", 
        "Ignored for hex.", 
        "Ignored for hex.",
        "Prefix non-zero output with '0x' or '0X'."
    ],
    "Pointer (p)": [
        "Pads with zeros (on the left).", 
        "Left-align within the given field width.", 
        "Ignored for pointers.", 
        "Ignored for pointers.",
        "Always prefix with '0x'."
    ],
}

# Create DataFrame with filtered data
df_filtered = pd.DataFrame(data_filtered)

# PDF setup for filtered table
pdf = FPDF()
pdf.set_auto_page_break(auto=True, margin=15)
pdf.add_page()

# Add Title
pdf.set_font('Arial', 'B', 12)
pdf.cell(200, 10, 'Summary of printf Flags and Their Interactions (Filtered Data Types)', ln=True, align='C')

# Add table headers
pdf.set_font('Arial', 'B', 10)
pdf.cell(20, 10, 'Flag', border=1)
for col in df_filtered.columns[1:]:
    pdf.cell(35, 10, col, border=1)
pdf.ln()

# Add table data
pdf.set_font('Arial', '', 10)
for i in range(len(df_filtered)):
    pdf.cell(20, 10, df_filtered.iloc[i, 0], border=1)  # Flag column
    for j in range(1, len(df_filtered.columns)):
        pdf.cell(35, 10, df_filtered.iloc[i, j], border=1)  # Data type columns
    pdf.ln()

# Save PDF
output_pdf_filtered_path = '/mnt/data/printf_flags_filtered_summary.pdf'
pdf.output(output_pdf_filtered_path)

output_pdf_filtered_path
