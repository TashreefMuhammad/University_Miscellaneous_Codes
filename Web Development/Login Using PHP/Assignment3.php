<!doctype html>
<html lang="en">
<head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="bootstrap/css/bootstrap.min.css" />
    <link rel="stylesheet" href="bootstrap/css/main.css" />

    <title>Assignment 3</title>
</head>
<body>
    <div class="container-fluid">
        <div class="jumbotron d-flex align-items-center" style="margin: 0px; padding: 0px">

            <!-- The Left Portion -->
            <div class="regularinfo">
                <p style="font-size: 50px">Ahsanullah university of Science and Technology</p>
                <p class="font-weight-bold" style="font-size: 100px">CSE 3.1</p>
            </div>

            <!-- The Right Portion -->
            <div class="takeinfo">
                <p class="font-weight-bold" style="font-size: 50px">Contact Us</p>

                    <!-- Form -->
                    <form id="contact" action="bootstrap/DataCode.php" method="post">
                    <div class="form_element">
                        <label for="name" style="font-size: 20px">Name:</label>
                        <input placeholder="Enter Name" type="text" name="name" id="name"required>
                    <br>
                    <br>
                        <label for="email" style="font-size: 20px">E-mail:</label>
                        <input placeholder="Enter Email" type="email" name="email" id="email" required>
                    <br>
                    <br>
                        <label for="Message" style="font-size: 20px">Message:</label>
                        <textarea placeholder="Enter Message" name="message" id="message" required></textarea>
                    <br>
                    <br>
                    <!-- On Submit File Goes to DataCode. There the Data is Written at CSV File 'Data' -->
                        <button name="submit" type="submit" id="contact-submit">Submit</button>
                    </div>
                    </form>
                    <br>
                    <br>
                    <!-- On pressing Show Data hyperlinked to GenerateTable where a table is generated to show all data
                    of 'Data' File -->
                    <a href="bootstrap/GenerateTable.php" class="btn btn-primary btn-block" role="button">Show Data</a>
            </div>
        </div>
    </div>
	<!-- Optional JavaScript -->
	<!-- jQuery first, then Popper.js, then Bootstrap JS -->
	<script src="js/jquery.min.js"></script>
	<script src="js/popper.min.js"></script>
	<script src="js/bootstrap.min.js"></script>
</body>
</html>