from bs4 import BeautifulSoup


with open('test.html')as f:
    html = f.readlines()

html = "".join(html)

# print(html)
# html = """
#     <tr>
#         <td>
#             <input id="ContentPlaceHolder1_grd_project_chkproject_0" type="checkbox" name="ctl00$ContentPlaceHolder1$grd_project$ctl02$chkproject">
#             <input type="hidden" name="ctl00$ContentPlaceHolder1$grd_project$ctl02$hddprojectId" id="ContentPlaceHolder1_grd_project_hddprojectId_0" value="41737">
#             <!-- Other hidden input fields -->
#         </td>
#         <td>
#             <div>Autonomous Vehicle Navigation with Reinforcement Learning</div>
#         </td>
#         <!-- Other columns with data -->
#     </tr>
#     <!-- Additional rows -->
# # # """
soup = BeautifulSoup(html, 'lxml')

# Find all rows in the table
rows = soup.find_all('tr')
# print(rows[1])
rows = rows.__iter__()
next(rows)
# Iterate through each row
for row in rows:
    # Extract data from each column in the row
    # checkbox = row.find('input', {'type': 'checkbox'})
    # project_name = row.find('div').text
    project_name = row.find("//*[@id=\"ContentPlaceHolder1_grd_project\"]/tbody/tr[2]/td[2]/div").text
    objective = row.find('//*[@id="ContentPlaceHolder1_grd_project_lbObjective_0"]').text
    # objective = row.find('span', {'id': 'ContentPlaceHolder1_grd_project_lbObjective_0'}).text
    # outcome = row.find('span', {'id': 'ContentPlaceHolder1_grd_project_lbOutCome_0'}).text
    # skills = row.find('span', {'id': 'ContentPlaceHolder1_grd_project_lbSkills_0'}).text
    # supervisor = row.find('span', {'id': 'ContentPlaceHolder1_grd_project_lbSuperVisior_0'}).text
    # co_supervisor = row.find('span', {'id': 'ContentPlaceHolder1_grd_project_lbCoSuperVisior_0'}).text
    # total = row.find('span', {'id': 'ContentPlaceHolder1_grd_project_lbtotal_0'}).text
    print(project_name)

