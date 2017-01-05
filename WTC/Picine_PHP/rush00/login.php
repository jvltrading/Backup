<?php
//This section of the script will connect to the database and validate wether a user is logged in or not

$user_name = "root";
$pass = "solomi";
$database = "secure_login";
$server = "127.0.0.1";

if ($_SERVER['REQUEST_METHOD'] == 'POST'){
    $uname = $_POST['username'];
    $pword = $_POST['password'];
    $uname = htmlspecialchars($uname);
    $pword = htmlspecialchars($pword);
    $db_handle = mysqli_connect($server, $user_name, $pass, $database);
    if (mysqli_select_db($db_handle, $database))
    {
        $SQL = "SELECT * FROM members WHERE username='$uname' AND password='$pword'";
        $result = mysqli_query($db_handle, $SQL);
        $num_rows = mysqli_num_rows($result);
        if ($result)
        {
            if ($num_rows > 0)
            {
                session_start();
                $_SESSION['login'] = "1";
                header ("Location: welcome.php");
            }
            else 
            {
                session_start();
                $_SESSION['login'] = "";
                header ("Location: register.php");
            }
        }
        else {
            echo "Error logging on";
        }
        mysqli_close($db_handle);
    }
    else
        echo "error opening database, please try again later.";
}
?>

<html>
    <head>
        <link rel="stylesheet" type="text/css" href="login.css">
        <title>Epic | Login</title>
    </head>
    <body>
        <div id="image">
            <img id="image" src="epic-text.jpg"/> <br />
        </div>
<form action="login.php" method="post">
  <div class="container">
    <label><b>Username</b></label>
    <input type="text" placeholder="Enter Username" name="username" required>
    <label><b>Password</b></label>
    <input type="password" placeholder="Enter Password" name="password" required>
    <button type="submit">Login</button>
  <div class="create_forgot">
      <br/>
      <p style="color:red; text-align:center"><strong>Don't have an account?</strong></p>
      <a href="register.php"><button type="button" class="register">Create an Account</button></a>
      </div>
    </div>
        </form>
    </body>
</html>