Imports System
Imports Tinkerforge

Module ExampleSimple
    Const HOST As String = "localhost"
    Const PORT As Integer = 4223
    Const UID As String = "XYZ" ' Change XYZ to the UID of your Distance IR Bricklet

    Sub Main()
        Dim ipcon As New IPConnection() ' Create IP connection
        Dim dir As New BrickletDistanceIR(UID, ipcon) ' Create device object

        ipcon.Connect(HOST, PORT) ' Connect to brickd
        ' Don't use device before ipcon is connected

        ' Get current distance
        Dim distance As Integer = dir.GetDistance()
        Console.WriteLine("Distance: " + (distance/10.0).ToString() + " cm")

        Console.WriteLine("Press key to exit")
        Console.ReadLine()
        ipcon.Disconnect()
    End Sub
End Module
