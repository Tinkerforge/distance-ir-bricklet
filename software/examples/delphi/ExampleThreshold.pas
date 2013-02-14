program ExampleThreshold;

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
    procedure ReachedCB(sender: TBrickletDistanceIR; const distance: word);
    procedure Execute;
  end;

const
  HOST = 'localhost';
  PORT = 4223;
  UID = '6Vw'; { Change to your UID }

var
  e: TExample;

{ Callback for distance smaller than 20 cm }
procedure TExample.ReachedCB(sender: TBrickletDistanceIR; const distance: word);
begin
  WriteLn(Format('Distance is smaller than 20 cm: %f cm', [distance/10.0]));
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

  { Get threshold callbacks with a debounce time of 10 second (10000ms) }
  dr.SetDebouncePeriod(10000);

  { Register threshold reached callback to procedure ReachedCB }
  dr.OnDistanceReached := {$ifdef FPC}@{$endif}ReachedCB;

  { Configure threshold for "smaller than 20cm" (unit is mm) }
  dr.SetDistanceCallbackThreshold('<', 20*10, 0);

  WriteLn('Press key to exit');
  ReadLn;
  ipcon.Destroy; { Calls ipcon.Disconnect internally }
end;

begin
  e := TExample.Create;
  e.Execute;
  e.Destroy;
end.
