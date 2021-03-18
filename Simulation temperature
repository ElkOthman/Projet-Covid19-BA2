import numpy as np
import smtplib, ssl
import random
import matplotlib.pyplot as plt
import time

context = ssl.create_default_context()
server = smtplib.SMTP("smtp.gmail.com", 587)
server.starttls(context=context)

server.login("blabla@gmail.com", "email_password")

loop = True

from time import sleep

x1 = np.linspace(0, 24, 40)

# Patient âgé de 11 à 65 ans

y1 = []
y2 = []
y3 = []

print("Entrez votre âge : ")
age = int(input())
print("Entrez votre prénom :")
prenom = str(input())
print("Entrez votre adresse mail :")
adresse = str(input())

for i in x1:
    y3.append(
        0.000000800327038 * i ** 7 - 0.000071541719253 * i ** 6 + 0.002481109976758 * i ** 5 - 0.041882649866184 * i ** 4 \
        + 0.353032950997121 * i ** 3 - 1.361122705704199 * i ** 2 + 1.931238521887565 * i + 37)

if age >= 11 and age < 65:
    for i in x1:
        y1.append(
            0.000000000133132 * i ** 11 - 0.000000017557244 * i ** 10 + 0.000000989358945 * i ** 9 - 0.000031054446422 * i ** 8 \
            + 0.00059356937429 * i ** 7 - 0.007103046711451 * i ** 6 + 0.052892268364286 * i ** 5 - 0.23815948972801 * i ** 4 \
            + 0.622743912073025 * i ** 3 - 0.868051437407272 * i ** 2 + 0.271730005784336 * i + 37)
    courbe = random.choice([y1, y2])

# Patient âgé de plus de 65 ans
elif age >= 65:
    for i in x1:
        y2.append(
            0.000000000133132 * i ** 11 - 0.000000017557244 * i ** 10 + 0.000000989358945 * i ** 9 - 0.000031054446422 * i ** 8 \
            + 0.00059356937429 * i ** 7 - 0.007103046711451 * i ** 6 + 0.052892268364286 * i ** 5 - 0.23815948972801 * i ** 4 \
            + 0.622743912073025 * i ** 3 - 0.868051437407272 * i ** 2 + 0.271730005784336 * i + 37 - 0.1)
    courbe = random.choice([y3])

print("Etes-vous atteint(e) de la BPCO ? Si oui, entrez 1 ; Si non, entrez 2 :")
bpco = int(input())
x = range(0, 24)
print(courbe)
temperature = []
g = []
taux = []
toux = 0
for i in range(24):
    taux.append(random.randint(80, 100))
    g.append(random.uniform(-2, 2))
    temperature.append(courbe[i])
    t = round(temperature[i], 1)
    if g[i] >= 1.6 or g[i] <= -1.6:
        toux += 1

    if bpco == 2:
        if taux[i] <= 93:
            if toux >= 3:
                if t >= 38:
                    if t >= 38.3:

                        subject = str(prenom) + " " + str(age) + ' ans en etat a surveiller'

                        msg = "Le taux de SpO2 de " + str(prenom) + " " + str(age) + " ans est de " + str(
                            taux[i]) + ", sa temperature s'aggrave et est de" + str(t) + "C et " + str(
                            prenom) + " vient de tousser."

                        message = 'Subject: {}\n\{}'.format(subject, msg)

                        reciever = adresse

                        server.sendmail("blabla@gmail.com", reciever, message)
                        sleep(30)
                    else:
                        subject = str(prenom) + str(age) + ' ans en etat a surveiller'

                        msg = "Le taux de SpO2 de " + str(prenom) + " " + str(age) + " ans est de " + str(
                            taux[i]) + ", sa temperature est de" + str(t) + "C et " + str(prenom) + " vient de tousser"

                        message = 'Subject: {}\n\{}'.format(subject, msg)

                        reciever = adresse

                        server.sendmail("blabla@gmail.com", reciever, message)
                        sleep(30)
                else:
                    subject = str(prenom) + " " + str(age) + ' ans en etat a surveiller'

                    msg = "Le taux de SpO2 de " + str(prenom) + " " + str(age) + " ans est de " + str(
                        taux[i]) + " et " + str(prenom) + " vient de tousser"

                    message = 'Subject: {}\n\{}'.format(subject, msg)

                    reciever = adresse

                    server.sendmail("blabla@gmail.com", reciever, message)
                    sleep(30)
            else:

                if t >= 38:
                    if t >= 38.3:

                        subject = str(prenom) + " " + str(age) + ' ans en etat a surveiller'

                        msg = "Le taux de SpO2 de " + str(prenom) + " " + str(age) + " ans est de  " + str(
                            taux[i]) + "et sa temperature s'aggrave et est de " + str(t) + "C."

                        message = 'Subject: {}\n\n{}'.format(subject, msg)

                        reciever = adresse

                        server.sendmail("blabla@gmail.com", reciever, message)
                        sleep(30)
                    else:
                        subject = str(prenom) + " " + str(age) + ' ans en etat a surveiller'

                        msg = "Le taux de SpO2 de " + str(prenom) + " " + str(age) + " ans est de  " + str(
                            taux[i]) + "et sa temperature est de " + str(t) + "C."

                        message = 'Subject: {}\n\n{}'.format(subject, msg)

                        reciever = adresse

                        server.sendmail("blabla@gmail.com", reciever, message)
                        sleep(30)

                else:
                    subject = str(prenom) + " " + str(age) + ' ans en etat a surveiller'

                    msg = "Le taux de SpO2 de " + str(prenom) + " " + str(age) + " ans est de  " + str(taux[i])
                    message = 'Subject: {}\n\n{}'.format(subject, msg)

                    reciever = adresse

                    server.sendmail("blabla@gmail.com", reciever, message)
                    sleep(30)

        elif taux[i] > 93:
            if toux >= 3:
                if t >= 38:
                    if t >= 38.3:

                        subjet = str(prenom) + " " + str(age) + ' ans en etat a surveiller'

                        msg = "La temperature de " + str(prenom) + " " + str(age) + " ans s'aggrave et est de " + str(
                            t) + "C et " + str(prenom) + " vient de tousser."

                        message = 'Subject: {}\n\{}'.format(subject, msg)

                        reciever = adresse

                        server.sendmail("blabla@gmail.com", reciever, message)
                        sleep(30)
                    else:
                        subjet = str(prenom) + " " + str(age) + ' ans en etat a surveiller'

                        msg = "La temperature de " + str(prenom) + " " + str(age) + " ans est de " + str(
                            t) + "C et " + str(prenom) + " vient de tousser."

                        message = 'Subject: {}\n\{}'.format(subject, msg)

                        reciever = adresse

                        server.sendmail("blabla@gmail.com", reciever, message)
                        sleep(30)
                else:
                    subjet = str(prenom) + " " + str(age) + ' ans en etat a surveiller'

                    msg = str(prenom) + " " + str(age) + " ans vient de tousser"

                    message = 'Subject: {}\n\{}'.format(subject, msg)

                    reciever = adresse

                    server.sendmail("blabla@gmail.com", reciever, message)
                    sleep(30)
            else:
                if t >= 38:
                    if t >= 38.3:

                        subjet = str(prenom) + " " + str(age) + ' ans en etat a surveiller'

                        msg = "La temperature de " + str(prenom) + " " + str(age) + " ans s'aggrave et est de " + str(
                            t) + "C."

                        message = 'Subject: {}\n\{}'.format(subject, msg)

                        reciever = adresse

                        server.sendmail("blabla@gmail.com", reciever, message)
                        sleep(30)
                    else:
                        subjet = str(prenom) + " " + str(age) + ' ans en etat a surveiller'

                        msg = "La temperature de " + str(prenom) + " " + str(age) + " ans est de " + str(t) + "C."

                        message = 'Subject: {}\n\{}'.format(subject, msg)

                        reciever = adresse

                        server.sendmail("blabla@gmail.com", reciever, message)
                        sleep(30)

    elif bpco == 1:
        if taux[i] > 92 or taux[i] < 88:
            if toux >= 3:
                if t >= 38:
                    if t >= 38.3:

                        subject = str(prenom) + " " + str(age) + ' ans atteint(e) de la bpco est en etat a surveiller'

                        msg = "Le taux de SpO2 du patient est de  " + str(
                            taux[i]) + ", sa temperature s'aggrave et est de " + str(t) + "C et " + str(
                            prenom) + " vient de tousser"

                        message = 'Subject: {}\n\n{}'.format(subject, msg)

                        reciever = adresse

                        server.sendmail("blabla@gmail.com", reciever, message)
                        sleep(30)
                    else:
                        subject = str(prenom) + " " + str(age) + ' ans atteint(e) de la bpco est en etat a surveiller'

                        msg = "Le taux de SpO2 du patient est de  " + str(taux[i]) + ", sa temperature est de " + str(
                            t) + "C et " + str(prenom) + " vient de tousser"

                        message = 'Subject: {}\n\n{}'.format(subject, msg)

                        reciever = adresse

                        server.sendmail("blabla@gmail.com", reciever, message)
                        sleep(30)

                else:

                    subject = str(prenom) + " " + str(age) + ' ans atteint(e) de la bpco est en etat a surveiller'

                    msg = "Le taux de SpO2 de " + str(prenom) + " " + str(age) + ' ans  est de ' + str(
                        taux[i]) + " et " + str(prenom) + " vient de tousser"

                    message = 'Subject: {}\n\n{}'.format(subject, msg)

                    reciever = adresse

                    server.sendmail("blabla@gmail.com", reciever, message)
                    sleep(30)
            else:
                if t >= 38:
                    if t >= 38.3:
                        subject = str(prenom) + " " + str(age) + ' ans atteint(e) de la bpco est en etat a surveiller'

                        msg = "Le taux de SpO2 de " + str(prenom) + " " + str(age) + " ans est de  " + str(
                            taux[i]) + ", sa temperature s'aggrave et est de " + str(t) + "C."

                        message = 'Subject: {}\n\n{}'.format(subject, msg)

                        reciever = adresse

                        server.sendmail("blabla@gmail.com", reciever, message)
                        sleep(30)
                    else:
                        subject = str(prenom) + " " + str(age) + ' ans atteint(e) de la bpco est en etat a surveiller'

                        msg = "Le taux de SpO2 de " + str(prenom) + " " + str(age) + " ans est de  " + str(
                            taux[i]) + ", sa temperature est de " + str(t) + "C."

                        message = 'Subject: {}\n\n{}'.format(subject, msg)

                        reciever = adresse

                        server.sendmail("blabla@gmail.com", reciever, message)
                        sleep(30)
                else:
                    subject = str(prenom) + " " + str(age) + ' ans atteint(e) de la bpco est en etat a surveiller'

                    msg = "Le taux de SpO2 de " + str(prenom) + " " + str(age) + " ans est de  " + str(taux[i])

                    message = 'Subject: {}\n\n{}'.format(subject, msg)

                    reciever = adresse

                    server.sendmail("blabla@gmail.com", reciever, message)
                    sleep(30)

        else:
            if toux >= 3:
                if t >= 38:
                    if t >= 38.3:
                        subject = "Apparition d'un symptome"

                        msg = str(prenom) + " " + str(
                            age) + " ans vient de tousser, sa temperature s'aggrave et est de " + str(t) + "C"

                        message = 'Subject: {}\n\n{}'.format(subject, msg)

                        reciever = adresse

                        server.sendmail("blabla@gmail.com", reciever, message)
                        sleep(30)
                    else:
                        subject = "Apparition d'un symptome"

                        msg = str(prenom) + " " + str(age) + " ans vient de tousser et sa temperature est de " + str(
                            t) + "C"

                        message = 'Subject: {}\n\n{}'.format(subject, msg)

                        reciever = adresse

                        server.sendmail("blabla@gmail.com", reciever, message)
                        sleep(30)
                else:
                    subject = "Apparition d'un symptome"

                    msg = str(prenom) + " " + str(age) + " ans vient de tousser."

                    message = 'Subject: {}\n\n{}'.format(subject, msg)

                    reciever = adresse

                    server.sendmail("blabla@gmail.com", reciever, message)
                    sleep(30)
            else:
                if t >= 38:
                    if t >= 38.3:
                        subject = "Apparition d'un symptome"

                        msg = "La temperature de " + str(prenom) + " " + str(age) + " est de " + str(t) + "C"

                        message = 'Subject: {}\n\n{}'.format(subject, msg)

                        reciever = adresse

                        server.sendmail("blabla@gmail.com", reciever, message)
                        sleep(30)
                    else:
                        subject = "Apparition d'un symptome"

                        msg = "La temperature de " + str(prenom) + " " + str(age) + " s'aggrave et est de " + str(
                            t) + "C"

                        message = 'Subject: {}\n\n{}'.format(subject, msg)

                        reciever = adresse

                        server.sendmail("blabla@gmail.com", reciever, message)
                        sleep(30)

server.quit()

plt.plot(x1, courbe)
plt.show()

plt.plot(x, taux)
plt.grid(True)
plt.show()

plt.plot(x, g)
plt.grid(True)
plt.show()

