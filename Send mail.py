import smtplib #import library

server = smtplib.SMTP_SSL("smtp.gmail.com",465)

server.login("blabla@gmail.com","mail_password") #connect to email



# Writing message

subject = 'Message de niveau 5'

msg = "Hello"

message = 'Subject: {}\n\n{}'.format(subject, msg)

reciever = 'blabla@gmail.com'

server.sendmail("blabla@gmail.com",reciever ,message)

# disconnect from server
server.quit()
