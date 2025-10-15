alldogs = []

num_dog_surr = int(input("Number of dogs surrendering: "))
count = 0
#while num_dog_surr > 0:
#for i in range(num_dog_surr):
while count < num_dog_surr:
    dogs = list()
    
    # name
    dogname = input ("Dog Name: ").capitalize()
    blankd = 40 - len(dogname) - len("Dog Name: ")
    dogs.append("Name: " + dogname)

    # gender and fixed
    while True: 
        gender = input ("Gender of dog: ").upper()
        if gender == "FEMALE":
            spay = input ("Is the dog spayed? ").upper()
            if spay == "YES":
                fixed = "Spayed"
            else: 
                fixed = "Not Spayed"
            break
        elif gender == "MALE":
            neutered = input ("Is the dog neutered? ").upper()
            if neutered == "YES":
                fixed = "Neutered"
            else: 
                fixed = "Not Neutered"
            break
        else:
            print ("Error: Enter either Female or Male for gender.")
    dogs.append("Gender: " + gender)
    dogs.append("Fixed?: " + fixed)

    #color
    while True:
        col = input ("What color is the dog (Fawn, Brindle, White with Hearing, White no Hearing)? ").upper()
        if col == "FAWN":
            color = col
            break
        elif col == "BRINDLE":
            color = col
            break
        elif col == "WHITE WITH HEARING":
            color = col
            break
        elif col == "WHITE NO HEARING":
            color = col
            break
        else: 
            print ("Error: Please input either Fawn, Brindle, White with hearing, or white no hearing.")
    dogs.append("Fur Color: " + color)

    # tail
    while True:
        tail = input ("Is the tail docked or natural (long tail)? ").upper() 
        # without this line inside ^ it'll run forever
        if tail == "DOCKED":
            cuttail = "Tail: Docked"
            break
        elif tail == "NATURAL":
            cuttail = "Tail: Natural (Long Tail)"
            break
        else:
            print ("Error: Invalid input. Please put Docked or Natural. ")
    dogs.append("Tail: " + cuttail)
    blankct = 40 - len(color) - len("Color: ")

    # weight
    while True:
        weight = int(input("How much does the dog weigh? (in lbs): "))
        if (weight < 20) or (weight > 200):
            print ("Error: Please input a valid weight between 20 and 200.")
        else:
            doglbs = weight
            break
    dogs.append("Weight: " + str(doglbs))


    #age 
    while True:
        age = int(input("Please input dogs age: "))
        if (age > 0) and (age < 20):
            d_age = age
            break
        else:
            print ("Error: Invalid Input. Please put in a valid age.")
    dogs.append("Age: " + str(d_age))

    blankwa = 40 - len(str(doglbs)) - len ("Weight: ")

    # ears 
    while True:
        ears = input ("Are the dogs ears floppy or cropped? ").upper()
        if ears == "FLOPPY":
            cutear = "Ears: Natural (Floppy)"
            break
        elif ears == "CROPPED":
            cutear = "Ears: Cropped"
            break
        else: 
            print ("Error: Invalid Input. Please put either floppy or cropped.")
    dogs.append("Ear: " + cutear)

    # microchip
    while True:
        chip = input ("Is the dog microchipped? ").upper()
        if chip == "YES":
            micronum = input ("What is the microchip number? ")
            microcomp = input ("What is the microchip company name? ").capitalize()
            break
        elif chip == "NO":
            micronum = ""
            microcomp = ""
            break 
        else:
            print ("Error: Invalid Input. Please input Yes or No.")
    dogs.append("Microchip #: " + micronum)
    dogs.append("Microchip Company: " + microcomp)


    blankmic = 40 - len("Microchipped? Yes") - len(micronum) - len(microcomp)

    alldogs.append(dogs)
    count += 1
    #num_dog_surr -= 1


print ("All dogs entered:")
#for dog in dogs:
    #print (dog)

dog_number = 1
for dog in alldogs:
    print("\nDog", dog_number, ":")
    for info in dog:
        print(info)
    dog_number += 1