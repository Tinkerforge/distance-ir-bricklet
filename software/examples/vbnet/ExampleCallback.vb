Imports System
Imports Tinkerforge

Module ExampleCallback
    Const HOST As String = "localhost"
    Const PORT As Integer = 4223
    Const UID As String = "XYZ" ' Change XYZ to the UID of your Distance IR Bricklet

    ' Callback subroutine for distance callback (parameter has unit mm)
    Sub DistanceCB(ByVal sender As BrickletDistanceIR, ByVal distance As Integer)
        Console.WriteLine("Distance: " + (distance/10.0).ToString() + " cm")
    End Sub

    Sub Main()
        Dim ipcon As New IPConnection() ' Create IP connection
        Dim dir As New BrickletDistanceIR(UID, ipcon) ' Create device object

        ipcon.Connect(HOST, PORT) ' Connect to brickd
        ' Don't use device before ipcon is connected

        ' Register distance callback to subroutine DistanceCB
        AddHandler dir.DistanceCallback, AddressOf DistanceCB

        ' Set period for distance callback to 0.2s (200ms)
        ' Note: The distance callback is only called every 0.2 seconds
        '       if the distance has changed since the last call!
        dir.SetDistanceCallbackPeriod(200)

        Console.WriteLine("Press key to exit")
        Console.ReadLine()
        ipcon.Disconnect()
    End Sub
End Module
