import random

numero = random.randint(1, 100)

print("===== TIENES 5 INTENTOS PARA ADIVINAR EL NUMERO ENTRE 1 Y 100 =====")

# Intento 1
int1 = int(input("Intento 1: "))
if int1 < 1 or int1 > 100:
    print("Número fuera de rango.")
else:
    if int1 == numero:
        print(f"Acertaste, el número era {numero}.")
    else:
        if int1 > numero:
            print("El número es menor.")
        if int1 < numero:
            print("El número es mayor.")

        # Intento 2
        int2 = int(input("Intento 2: "))
        if int2 < 1 or int2 > 100:
            print("Número fuera de rango.")
        else:
            if int2 == numero:
                print(f"Acertaste, el número era {numero}.")
            else:
                if int2 > numero:
                    print("El número es menor.")
                if int2 < numero:
                    print("El número es mayor.")

                # Intento 3
                int3 = int(input("Intento 3: "))
                if int3 < 1 or int3 > 100:
                    print("Número fuera de rango.")
                else:
                    if int3 == numero:
                        print(f"Acertaste, el número era {numero}.")
                    else:
                        if int3 > numero:
                            print("El número es menor.")
                        if int3 < numero:
                            print("El número es mayor.")

                        # Intento 4
                        int4 = int(input("Intento 4: "))
                        if int4 < 1 or int4 > 100:
                            print("Número fuera de rango.")
                        else:
                            if int4 == numero:
                                print(f"Acertaste, el número era {numero}.")
                            else:
                                if int4 > numero:
                                    print("El número es menor.")
                                if int4 < numero:
                                    print("El número es mayor.")

                                # Intento 5
                                int5 = int(input("Intento 5: "))
                                if int5 < 1 or int5 > 100:
                                    print("Número fuera de rango.")
                                else:
                                    if int5 == numero:
                                        print(f"Acertaste, el número era {numero}.")
                                    else:
                                        if int5 > numero:
                                            print("El número es menor.")
                                        if int5 < numero:
                                            print("El número es mayor.")
                                        print("Se acabaron los intentos, el número era:", numero)
