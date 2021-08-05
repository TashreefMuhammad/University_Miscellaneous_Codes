<?php
if(isset($_POST['submit'])){
    if(!empty($_POST['name']) && !empty($_POST['email']) && !empty($_POST['message'])){
        $name = htmlspecialchars(stripslashes(trim($_POST['name'])));
        $email = htmlspecialchars(stripslashes(trim($_POST['email'])));
        $msg = htmlspecialchars(stripslashes(trim($_POST['message'])));

        $file = fopen('Data.csv', 'a');

        $contactData  = array(
            0 => $name,
            1 => $email,
            2 => $msg
        );

        fputcsv($file, $contactData);
        fclose($file);
    }
}
// After Insertion of Data, return to the main page
header("Location: ../Assignment3.php");
?>