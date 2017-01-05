<?php
session_start();
$server = "127.0.0.1";
$user_name = "root";
$pass = "solomi";
$dbname = "accounts";
$errorMessage = "";

if ($_SERVER['REQUEST_METHOD'] == 'POST')
{
    $pword = $_POST['password'];
    $uname = $_POST['username'];
    
    $pword = htmlspecialchars($pword);
    $conn = mysqli_connect($server, $user_name, $pass, $dbname);

    if ($conn)
    {
        $quer = "SELECT EXISTS(SELECT * FROM accinfo WHERE username = $uname)";
        $result = mysqli_query($quer);
        $num_rows = mysqli_num_rows($result);
    
        if ($num_rows > 0)
        {
            $errorMessage = "That Username already exists";
        }
        else
        {
            $sql = "INSERT INTO accinfo (username, password) VALUES('$uname', '$pword')";
            if (mysqli_query($conn, $sql))
            {
                echo "Your account has been successfully activated";
                header("Location: ../index.php");
            }
            else{
                $errorMessage = "Error Creating your Account";
            }
        }
    }
    mysqli_close($conn);
}
     
    /*$sql = "INSERT INTO accinfo (username, password) VALUES('$uname', '$pword')";
    if (mysqli_query($conn, $sql))
    {
        echo "Your account has been successfully activated";
        sleep(2);
        header("Location: ../index.php");
        
    }
    else
    {
        $errorMessage = "Error creating account";
    }*/
?>

<html>
    <head>
        <link rel="stylesheet" type="text/css" href="main.css">
        <title>Epic | Register</title>
    </head>
        <body>
            <form action="register.php" method="post">
                <div class="container">
                    <label><b>Username</b></label>
                    <input type="text" placeholder="Enter username" name="username" required>
                    <label><b>Password</b></label>
                    <input type="password" placeholder="Enter Password" name="password" required><button type="submit">Create Account</button>
                </div>
            </form>
            <?php print $errorMessage ?>
            <div id="nav">
            <div class="row">
                <div id="home_logo">
                    <a href="landing.php">
                        <img src="small-img.png">
                    </a>
                </div>
                <ul id="home_menu">
                    <a class="styling_nav" href="landing.php">HOME</a>
                    <a class="styling_nav" href="store.php">STORE</a>
                    <a class="styling_nav">MY CART</a>
                    <a class="styling_nav" href="login.php">LOG IN</a>
                </ul>
            </div>
        </div>
    </body>
</html>