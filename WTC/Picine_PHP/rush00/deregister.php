<?php
$server = "127.0.0.1";
$user_name = "root";
$pass = "solomi";
$dbname = "secure_login";

if ($_SERVER['REQUEST_METHOD'] == 'POST')
{
    $pword = $_POST['password'];
    $pword = htmlspecialchars($pword);
    $conn = mysqli_connect($server, $user_name, $pass, $dbname);
    if (!$conn)
    {
        echo "Failed to open the database";
    }
    $sql = "DELETE FROM members WHERE password='$pword'";
    if (mysqli_query($conn, $sql))
    {
        echo "Your account has been successfully deactivated";
        sleep(2);
        header("Location: index.php");
        
    }
    else
    {
        echo "Error deleting record";
    }
    mysqli_close($conn);
}
?>
<html>
    <head>
        <link rel="stylesheet" type="text/css" href="main.css">
    </head>
    <body style="background-color:white">
        <div class="container">
        <form action="deregister.php" method="post">
            <label>Enter your Password below to permenantly delete your account:</label>
            <input type="password" placeholder="Enter Password" name="password" required>
            <button type="submit">Delete Account</button>
        </form>
        </div>
    </body>
</html>