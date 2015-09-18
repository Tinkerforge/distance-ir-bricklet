Imports System
Imports Tinkerforge

Module ExampleThreshold
    Const HOST As String = "localhost"
    Const PORT As Integer = 4223
    Const UID As String = "XYZ" ' Change to your UID

    ' Callback subroutine for distance reached callback (parameter has unit mm)
    Sub DistanceReachedCB(ByVal sender As BrickletDistanceIR, ByVal distance As Integer)
        Console.WriteLine("Distance: " + (distance/10.0).ToString() + " cm")
    End Sub

    Sub Main()
        Dim ipcon As New IPConnection() ' Create IP connection
        Dim dir As New BrickletDistanceIR(UID, ipcon) ' Create device object

        ipcon.Connect(HOST, PORT) ' Connect to brickd
        ' Don't use device before ipcon is connected

        ' Get threshold callbacks with a debounce time of 10 seconds (10000ms)
        dir.SetDebouncePeriod(10000)

        ' Register distance reached callback to subroutine DistanceReachedCB
        AddHandler dir.DistanceReached, AddressOf DistanceReachedCB

        ' Configure threshold for distance "smaller than 30 cm" (unit is mm)
        dir.SetDistanceCallbackThreshold("<"C, 30*10, 0)

        Console.WriteLine("Press key to exit")
        Console.ReadLine()
        ipcon.Disconnect()
    End Sub
End Module
