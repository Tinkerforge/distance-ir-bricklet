program ExampleCallback;

{$ifdef MSWINDOWS}{$apptype CONSOLE}{$endif}
{$ifdef FPC}{$mode OBJFPC}{$H+}{$endif}

uses
  SysUtils, IPConnection, BrickletDistanceIR;

type
  TExample = class
  private
    ipcon: TIPConnection;
    dr: TBrickletDistanceIR;
  public
    procedure DistanceCB(sender: TBrickletDistanceIR; const distance: word);
    procedure Execute;
  end;

const
  HOST = 'localhost';
  PORT = 4223;
  UID = '6Vw'; { Change to your UID }

var
  e: TExample;

{ Callback function for distance callback (parameter has unit mm) }
procedure TExample.DistanceCB(sender: TBrickletDistanceIR; const distance: word);
begin
  WriteLn(Format('Distance: %f cm', [distance/10.0]));
end;

procedure TExample.Execute;
begin
  { Create IP connection }
  ipcon := TIPConnection.Create;

  { Create device object }
  dr := TBrickletDistanceIR.Create(UID, ipcon);

  { Connect to brickd }
  ipcon.Connect(HOST, PORT);
  { Don't use device before ipcon is connected }

  { Set Period for distance callback to 0.2s (200ms)
    Note: The callback is only called every 200ms if the
          distance has changed since the last call! }
  dr.SetDistanceCallbackPeriod(200);

  { Register distance callback to procedure DistanceCB }
  dr.OnDistance := {$ifdef FPC}@{$endif}DistanceCB;

  WriteLn('Press key to exit');
  ReadLn;
  ipcon.Destroy;
end;

begin
  e := TExample.Create;
  e.Execute;
  e.Destroy;
end.
